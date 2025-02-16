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
   // Read image
   cv::Mat img = cv::imread("./assets/images/DK.jpeg");
   cv::imshow("Image", img);
   // Convert image to hsv
   cv::Mat hsv;
   cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
   cv::imshow("HSV", hsv);
   // hsv format -> (min hue, min saturation , min value) -> (max hue, max saturation , max value)
   // RED mask =>
   // Mat mask1 = inRange(hsv, Scalar(0, 100, 0), Scalar(10, 255, 255));
   // YELLOW mask =>
   cv::Mat mask1;
   cv::inRange(hsv, cv::Scalar(15, 30, 150), cv::Scalar(36, 255, 255), mask1);
   cv::imshow("mask1", mask1);
   // BLUE mask =>
   cv::Mat mask2;
   cv::inRange(hsv, cv::Scalar(33, 52, 80), cv::Scalar(150, 200, 255), mask2);
   cv::imshow("mask2", mask2);
   // Final mask and masked
   cv::Mat mask;
   cv::bitwise_or(mask1, mask2, mask);
   cv::imshow("mask", mask);
   cv::Mat target;
   cv::bitwise_and(img, img, target, mask);
   cv::imshow("target", target);
   cv::waitKey(0);
   cv::destroyAllWindows();
   return 0;
}