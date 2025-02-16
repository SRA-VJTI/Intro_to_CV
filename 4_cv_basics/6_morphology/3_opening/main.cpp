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
#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "../include/morphology.hpp"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "usage: ./output <Image_Path>\n";
        return -1;
    }
    // Reading the Image
    cv::Mat source_image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    
    // Check if the image is created successfully or not
    if (!source_image.data) 
    {
        std::cout << "Could not open or find the image\n";
        return 0;
    }
    
    // creating container for output image according to size and type of source image
    cv::Mat temp1{source_image.size(), source_image.type()};
    cv::Mat output_image{source_image.size(), source_image.type()};
    
    //Applying erosion on source image
    int kernel_size_erosion = 3;
    temp1 = erosion(source_image, temp1, kernel_size_erosion);
    
    // Applying dilation on erroded image
    int kernel_size_dilation = 3;
    output_image = dilation(temp1, output_image, kernel_size_dilation);
    
    //Displaying both source and output image
    cv::namedWindow("source", cv::WINDOW_NORMAL);
    cv::imshow("source", source_image);
    cv::namedWindow("output", cv::WINDOW_NORMAL);
    cv::imshow("output", output_image);
    cv::waitKey();
    
    return 0;
}