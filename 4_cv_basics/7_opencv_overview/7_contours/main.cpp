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
   cv::Mat img;
   img = cv::imread("./assets/images/DK.jpeg");

   // 1. Convert to Grayscale

   cv::Mat gray;
   cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
   cv::imshow("Gray", gray);

   // 2. Apply Canny Edge detection

   cv::Mat edges;
   cv::Canny(gray, edges, 170, 250);
   cv::imshow("edges", edges);

   // 3. Find contours

   std::vector<std::vector<cv::Point>> contours;
   std::vector<cv::Vec4i> hierarchy;
   cv::findContours(edges, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
   cv::imshow("Canny edges after contouring", edges);
   
   // 4. Draw contours on image
   cv::Mat contourImg = cv::Mat::zeros(img.size(), CV_8UC3);
   for (size_t i = 0; i < contours.size(); i++)
   {
       cv::drawContours(img, contours, i, cv::Scalar(0, 255, 0), 2);
   }
   cv::imshow("Contours", img);
   cv::waitKey(0);
   cv::destroyAllWindows();
}