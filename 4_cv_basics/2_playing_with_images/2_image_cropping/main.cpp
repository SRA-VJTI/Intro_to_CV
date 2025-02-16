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
#include <opencv2/core.hpp>
 
using namespace std;

int main(){
    //reading an image and converting to cv::Mat format
    cv::Mat img = cv::imread("./assets/dog.jpeg", cv::IMREAD_GRAYSCALE);
    cv::Mat img4;
    cv::Vec3b* ptr;

    //obtaining the dimensions of the image
    int width = img.size().width;
    int height = img.size().height;
    cout << "Width of the image: " << width << endl;
    cout << "Height of the image: " << height << endl;

    cv::Mat img3 = cv::Mat::zeros(cv::Size(height/2, width/2), CV_8UC1);

    //image compression
    //resizing an image-this essentially removes every alternate pixel rows
    cv::resize(img, img4, cv::Size(width/2, height/2));

    //cropping an image
    // The general syntax for cropping an image is :
    // img(Range(start_row, end_row), Range(start_column, end_column));
    // The following is using OpenCV Mat container's inbuilt slicing functionality
    cv::Mat img2 = img(cv::Range(0, width/2), cv::Range(0, height/2));

    // The following implementation is using for loop to demonstrate pointer arithmetic
    for(int r = 0; r<height/2; r++)
    {
        for(int c = 0; c<width/2; c++)
        {
            img3.at<uchar>(c,r) = img.at<uchar>(c,r);
        }
    }

    //displaying the images
    cv::imshow("window", img);
    cv::imshow("resized image", img4);
    cv::imshow("cropped image", img2);
    cv::imshow("cropped image retake", img3);
    cv::waitKey(0);

    return 0;
}
