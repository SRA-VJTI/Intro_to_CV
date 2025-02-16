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
#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include "blob_detection.hpp"
using namespace std;

int main()
{
   cv::VideoCapture video(0); // Read input video
   int h = 0, s = 0, v = 0;
   
   while (video.isOpened())
   {
       cv::Mat frame;
       video.read(frame); // Read one frame from the video
       cv::namedWindow("Image", cv::WINDOW_NORMAL);
       cv::resizeWindow("Image", 640, 480);
       cv::imshow("Image", frame);
       
       if (cv::waitKey(10) == 'q') //Wait for "q" key to be pressed
       {
           cv::Rect bbox = cv::selectROI("Image", frame, false, false); // Select a region of interest on the image
           cv::Mat hsv;
           cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV); // Convert BGR color model to HSV
           cv::Mat obj_img = hsv(cv::Rect(bbox.x, bbox.y, bbox.width, bbox.height));
           tuple<double, double, double> medians = getMedianPixelValues(obj_img); // Find the median of HSV in the selected region.
           h = get<0>(medians);
           s = get<1>(medians);
           v = get<2>(medians);
           break;
       }
   }
   
   while (video.isOpened())
   {
       cv::Mat frame;
       video.read(frame);
       
       // Converting to hsv
       cv::Mat hsv;
       cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
       
       // Getting lower and upper bounds for h,s,v values
       cv::Scalar lower(h - 5, max(0, s - 50), max(0, v - 50));
       cv::Scalar upper(h + 5, min(s + 50, 255), min(v + 50, 255));
       
       // Masking
       cv::Mat masked;
       cv::inRange(hsv, lower, upper, masked);
       
       // Median Blur
       cv::Mat blur;
       cv::medianBlur(masked, blur, 5);
       
       // Performing bitwise_and using the 'blur' mask
       cv::Mat blob_mask;
       cv::bitwise_and(frame, frame, blob_mask, blur);
       cv::namedWindow("blob_mask", cv::WINDOW_NORMAL);
       cv::resizeWindow("blob_mask", 640, 480);
       cv::imshow("blob_mask", blob_mask);
       
       // Find contours
       vector<vector<cv::Point>> contours;
       vector<cv::Vec4i> hierarchy;
       cv::findContours(blur, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
       
       // Find largest contour
       int idx = 0;
       double current_max = 0;
       int counter = 0;
       for (const auto &n : contours)
       {
           double area = cv::contourArea(n);
           if (area > current_max)
           {
               current_max = area;
               idx = counter;
           }
           counter++;
       }
       
       // Draw the largest contour detected
       cv::drawContours(frame, contours, idx, cv::Scalar(0, 255, 255), 2);
       cv::namedWindow("Output", cv::WINDOW_NORMAL);
       cv::resizeWindow("Output", 640, 480);
       cv::imshow("Output", frame);
       
       if (cv::waitKey(10) == 'x')
       {
           cv::destroyAllWindows();
           video.release();
           break;
       }
   }
   return 0;
}