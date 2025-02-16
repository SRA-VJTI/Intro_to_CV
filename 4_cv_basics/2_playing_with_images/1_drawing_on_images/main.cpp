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

//including the necessary header files
#include <iostream>

//the following header files are from the OpenCV library for C++
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(){

    //creating a blank Mat image
    //img(height, width, cv 8-bit 3 channels, BGR)
    cv::Mat img(480, 720, CV_8UC3, cv::Scalar(0, 0, 0));
    
    //drawing horizontal line on image 
    for(int j = 100,i = 200;j <= 620;j++){
        img.at<cv::Vec3b>(i,j)[0] = 255;
        img.at<cv::Vec3b>(i,j)[1] = 255;
        img.at<cv::Vec3b>(i,j)[2] = 255;
    } 

    //draing vertical line on image 
    for(int i = 80,j = 300;i <= 400;i++){
        img.at<cv::Vec3b>(i,j)[0] = 255;
        img.at<cv::Vec3b>(i,j)[1] = 255;
        img.at<cv::Vec3b>(i,j)[2] = 255;        
    }

    //drawing an inclined line at 45 degree
    for(int i = 100;i <= 300;i++){
        for(int j = 100;j <= 300;j++){
            if(i == j){
                img.at<cv::Vec3b>(i,j)[0] = 255;
                img.at<cv::Vec3b>(i,j)[1] = 255;
                img.at<cv::Vec3b>(i,j)[2] = 255; 
            }
            else continue;
        }
    }
    cv::imshow("Drawing", img);
    cv::waitKey(0);

    return 0;
}
