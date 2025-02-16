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
#ifndef HELPER_HPP
#define HELPER_HPP

#include <opencv2/core.hpp>
#include <iostream>

/*
/ @brief finds sum of elements in a kernel about given co-ordinate(y, x)
/ @param Mat image
/ @param row (y)
/ @param col (x)
/ @param Kernel size
/ @return sum
*/
int kernel_sum(cv::Mat image, int row, int col, int Kernel_size);

/*
/ @brief performs erosion on source image and stores it in output image
/ @param Mat source_image
/ @param Mat output_image
/ @param int Kernel size
/ @return output_image after erosion
*/
cv::Mat erosion(cv::Mat source_image, cv::Mat output_image, int Kernel_size);

/*
/ @brief performs dilation on source image and stores it in output image
/ @param Mat source_image
/ @param Mat output_image
/ @param kernel size
/ @return output_image after erosion
*/
cv::Mat dilation(cv::Mat source_image, cv::Mat output_image, int kernel_size);

/*
/ @brief Gives difference between two given arrays
/ @param img_1 input image
/ @param img_2 input image
/ @param output container to store output image
/ @return output image
*/
cv::Mat difference(cv::Mat img_1, cv::Mat img_2, cv::Mat output);

#endif // !HELPER_HPP