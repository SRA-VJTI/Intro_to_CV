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
    // Reading input images (A and B)
    cv::Mat image1 = cv::imread("./assets/images/dummy1.jpg");
    cv::Mat image2 = cv::imread("./assets/images/purple_night.jpg");

    cv::resize(image1, image1, cv::Size(), 0.75, 0.75);
    cv::resize(image2, image2, cv::Size(), 0.75, 0.75);
    cv::imshow("Image1", image1);
    cv::imshow("Image2", image2);

    cv::Mat res;

    // Defining weights for the two images
    float alpha = 0.4, beta = (1 - alpha);

    // Blending image1 and image2
    // res = alpha * image1 + beta * image2 + gamma(0)
    cv::addWeighted(image1, alpha, image2, beta, 0.0, res);

    cv::namedWindow("Display Image");
    cv::resize(res, res, cv::Size(), 0.75, 0.75);
    cv::imshow("Display Image", res);
    cv::waitKey(0);

    return 0;
}
