/*
MIT License
Copyright (c) 2023 Society of Robotics and Automation
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(){
    // reading image and storing it in Mat format
    cv::Mat image = cv::imread("./assets/dog.jpeg", cv::IMREAD_GRAYSCALE);

    // storing the dimensions of the image
    int height = image.cols;
    int width = image.rows;

    // get the x and y axis values for translation so that the image can be moved in both directions
    float tx = float(width) / 4;
    float ty = float(height) / 4;

    cv::Mat img2 = cv::Mat::zeros(cv::Size(height, width), CV_8UC1);
    
    // create the translation matrix using tx and ty
    float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
    cv::Mat translation_matrix = cv::Mat(2, 3, CV_32F, warp_values);
    cout << translation_matrix;

    // save the resulting image in translated_image matrix
    cv::Mat translated_image;

    // apply affine transformation to the original image using the translation matrix
    cv::warpAffine(image, translated_image, translation_matrix, image.size());

    for(int r = 0; r < height - ty; r++)
    {
        for(int c = 0; c < width - tx; c++)
        {
            img2.at<uchar>(c, r) = image.at<uchar>(c + tx, r + ty);
        }
    }

    // display the original and the Translated images
    cv::imshow("Translated image", translated_image);
    cv::imshow("Translated Image Version", img2);
    cv::imshow("Original image", image);
    cv::waitKey(0);

    return 0;
}
