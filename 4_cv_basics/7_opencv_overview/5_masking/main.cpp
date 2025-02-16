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
#include <opencv2/opencv.hpp>
using namespace std;

int main()
{
    // Load two images
    cv::Mat img1 = cv::imread("./assets/images/DK.jpeg");
    cv::Mat img2 = cv::imread("./assets/images/bcci.png");
    cv::imshow("Image1", img1);

    // Getting the height, width and number of channels of the image
    // Creating ROI to put the logo on top - left corner
    int rows = img2.rows, cols = img2.cols, channels = img2.channels();

    // Cropping the img1
    cv::Mat roi = img1(cv::Rect(0, 0, rows, cols)).clone();

    // Converting the image to grayscale
    // Creating a mask of logo and create its inverse mask also
    cv::Mat img2gray;
    cv::cvtColor(img2, img2gray, cv::COLOR_BGR2GRAY);

    // each pixel having value more than 180(threshold)will be set to white i.e max_value(255) for a mask / HIGH
    // pixel values lower than threshold are set
    cv::Mat mask;
    cv::threshold(img2gray, mask, 180, 255, cv::THRESH_BINARY);

    // inverting colors
    cv::Mat mask_inv;
    cv::bitwise_not(mask, mask_inv);

    // Resizing mask
    cv::resize(mask, mask, roi.size());

    // Blacking-out the area of logo in ROI
    cv::Mat img1_bg;
    cv::bitwise_and(roi, roi, img1_bg, mask);

    // Take only region of logo from logo image.
    cv::Mat img2_fg;
    cv::bitwise_and(img2, img2, img2_fg, mask_inv);

    cv::Mat img2_fg_resized;
    cv::resize(img2_fg, img2_fg_resized, roi.size());

    // Put logo in ROI and modify the main image
    cv::Mat dst;
    cv::add(img1_bg, img2_fg_resized, dst);

    dst.copyTo(img1(cv::Rect(0, 0, rows, cols)));

    cv::imshow("Image2", img2);
    cv::imshow("ROI", roi);
    cv::imshow("Gray", img2gray);
    cv::imshow("mask", mask);
    cv::imshow("mask_inv", mask_inv);
    cv::imshow("BG", img1_bg);
    cv::imshow("FG", img2_fg);
    cv::imshow("dst", img1);
    cv::waitKey(0);
}
