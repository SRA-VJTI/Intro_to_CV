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

// rotate function returning mat object with parameters imagefile and angle
cv::Mat rotate(cv::Mat src, double angle)
{
    // Mat object for output image file
    cv::Mat dst;
    // defining point with respect to which to rotate
    cv::Point2f pt(src.cols/2., src.rows/2.);
    // Mat object for storing after rotation
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);
    // apply an affine transformation to image.
    cv::warpAffine(src, dst, r, cv::Size(src.cols, src.rows));
    //returning Mat object for output image file
    return dst;
}

int main(){
    // converting the image into Mat format
    cv::Mat img = cv::imread("./assets/dog.jpeg");
    cv::Mat img2;
    // obtaining the image dimensions
    int height=img.size().height;
    int width=img.size().width;

    img2 = rotate(img, 90);
    // displaying these images
    cv::imshow("rotated image", img2);
    cv::waitKey(0);
    
    return 0;
}