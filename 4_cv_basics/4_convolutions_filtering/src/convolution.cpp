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
#include <opencv2/opencv.hpp>
#include <iostream>

/*
    Specifying Namespaces
    Namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it. 
*/
using namespace std;

/// @brief : Convolution will help apply different kernels to your images yielding different results
/// @param   Original_image
/// @param   kernel
/// @return : An Output Image with the kernel applied
cv::Mat convolve(cv::Mat original_image, cv::Mat kernel){
    
    cv::Mat kernel_inv{kernel.size(), kernel.type()}, temp_kernel{kernel.size(), kernel.type()}, image_pad;
    cv::Mat resultant_image{original_image.size(), original_image.type()};
    
    // Using For Loops
    // for(int i = 0 ; i < kernel.rows ; i++ ){ cout<<"k"<<endl; kernel_inv.row(i) = kernel.row(kernel.rows - i - 1).clone(); }
    // temp_kernel = kernel_inv.clone();
    // for(int i = 0 ; i < kernel.cols ; i++ ){ kernel_inv.col(i) = temp_kernel.col(kernel.cols - i - 1).clone();}

    // Method 2: Simply using in-built functions
    // flip(kernel, kernel_inv, -1);  

    // Viewing channels for each image
    // cout<<original_image.channels()<<endl;

    // Adding Padding to the Image 
    cv::copyMakeBorder(original_image, image_pad, 1, 1, 1, 1, cv::BORDER_REPLICATE, cv::Scalar(0)); 

    for (int i = 1; i < image_pad.rows - 1; i++) 
    {   
        for (int j = 1; j < image_pad.cols - 1 ; j++) 
        {
            for(int ch = 0 ; ch < original_image.channels() ; ch++){

                double tmp = 0.0;
                for (int k = 0; k < kernel_inv.rows; k++) 
                {
                    for (int l = 0; l < kernel_inv.cols; l++) 
                    {
                        int x = j - 1 + l;
                        int y = i - 1 + k;  

                        if ((x >= 0 && x < image_pad.cols) && (y >= 0 && y < image_pad.rows)){
                            tmp += (double)image_pad.at<cv::Vec3b>(y, x).val[ch] * (double)kernel.at<double>(k, l);
                        }
                    }
                }

                resultant_image.at<cv::Vec3b>(i-1, j-1).val[ch] = cv::saturate_cast<uchar>(tmp);        // Why Unsigned? 
            }
        }
    }

    return resultant_image;
}