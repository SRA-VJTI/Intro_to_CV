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
#include "../include/morphology.hpp"

int kernel_sum(cv::Mat image, int row, int col, int Kernel_size)
{
	if (Kernel_size % 2 != 1 || Kernel_size < 3)
	{
		std::cout << "Kernel size should be of odd and greater than or equal to 3";
		return -1;
	}

	int sum = 0;
	int kernel = ((Kernel_size - 1) / 2);
	for (int i = row - kernel; i <= row + kernel; i++)
	{
		for (int j = col - kernel; j <= col + kernel; j++)
		{
			if (i >= 0 && j >= 0 && i < image.rows && j < image.cols)
			{
				sum = sum + (int)image.at<u_char>(i, j);
			}

		}
	}
	return sum;
}

cv::Mat erosion(cv::Mat source_image, cv::Mat output_image, int Kernel_size)
{
	for (int i = 0; i < source_image.rows; i++)
	{
		for (int j = 0; j < source_image.cols; j++)
		{
			if (kernel_sum(source_image, i, j, Kernel_size) != 255 * (Kernel_size*Kernel_size))
			{
				output_image.at<u_char>(i, j) = cv::saturate_cast<char>(0);
			}
			else
			{
				output_image.at<u_char>(i, j) = cv::saturate_cast<char>(255);
			}
		}
	}

	return output_image;
}

cv::Mat dilation(cv::Mat source_image, cv::Mat output_image, int kernel_size)
{
	for (int i = 0; i < source_image.rows; i++)
	{
		for (int j = 0; j < source_image.cols; j++)
		{
			if (kernel_sum(source_image, i, j, kernel_size) > 0)
			{
				output_image.at<u_char>(i, j) = cv::saturate_cast<char>(255);
			}
			else
			{
				output_image.at<u_char>(i, j) = cv::saturate_cast<char>(0);
			}
		}
	}

	return output_image;
}

cv::Mat difference(cv::Mat img_1, cv::Mat img_2, cv::Mat output)
{
	if (img_1.size() != img_2.size())
	{
		std::cout << "Images are of different sizes." << std::endl;
	}
	for (int i = 0; i < img_1.rows; i++)
	{
		for (int j = 0; j < img_1.cols; j++)
		{
			output.at<u_char>(i, j) = cv::saturate_cast<char>((abs)((int)img_1.at<u_char>(i, j) - (int)img_2.at<u_char>(i, j)));
		}
	}
	return output;
}