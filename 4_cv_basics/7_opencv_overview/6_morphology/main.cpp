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

// Function for erosion
cv::Mat erosion(cv::Mat input, int kernel_size)
{
   cv::Mat erode_output;
   cv::erode(input, erode_output, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernel_size, kernel_size)));
   return erode_output;
}

// Function for dilation
cv::Mat dilation(cv::Mat input, int kernel_size)
{
   cv::Mat dilate_output;
   cv::dilate(input, dilate_output, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernel_size, kernel_size)));
   return dilate_output;
}

// Function for opening
cv::Mat open(cv::Mat input, int kernel_size)
{
   cv::Mat open_output;
   cv::morphologyEx(input, open_output, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernel_size, kernel_size)));
   return open_output;
}

// Function for closing
cv::Mat close(cv::Mat input, int kernel_size)
{
   cv::Mat close_output;
   cv::morphologyEx(input, close_output, cv::MORPH_CLOSE, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernel_size, kernel_size)));
   return close_output;
}

// Function for gradient
cv::Mat gradient(cv::Mat input, int kernel_size)
{
   cv::Mat gradient_output;
   cv::morphologyEx(input, gradient_output, cv::MORPH_GRADIENT, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernel_size, kernel_size)));
   return gradient_output;
}

int main()
{
   cv::Mat image;
   // Reading image, in grayscale colorspace
   image = cv::imread("./assets/images/morph.png", cv::IMREAD_GRAYSCALE);
   // Resultant morphological transformation (change function name & kernel size)
   cv::Mat res = erosion(image, 5);
   // Displaying source image
   cv::namedWindow("Source");
   cv::imshow("Source", image);
   // Displaying transformed image
   cv::namedWindow("Morphology");
   cv::imshow("Morphology", res);
   cv::waitKey(0);
   return 0;
}