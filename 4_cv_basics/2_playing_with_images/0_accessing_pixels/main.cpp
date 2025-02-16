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

//declaring functions for different operations
cv::Mat black_out_rows(cv::Mat img, int height, int width);
cv::Mat change_blue(cv::Mat img, int height, int width);

int main() {
    //reading the image and converting it into cv::Mat format
    cv::Mat img = cv::imread("./assets/dog.jpeg");
    cv::Mat img2, img3;
    
    //obtaining the dimensions of the image
    int width = img.size().width;
    int height = img.size().height;
    int choice;
    
    cout << "Width of the image: " << width << endl;
    cout << "Height of the image: " << height << endl;
    
    cout << "You have a choice to make - 0 or 1. What will it be? ";
    cin >> choice;
    
    if (choice == 0) {
        //making alternate rows of pixels of the image black
        img2 = black_out_rows(img, height, width);
        //displaying the image on the screen. The image will be displayed until any key is pressed
        cv::imshow("window", img2);
        cv::waitKey(0);
    } else if (choice == 1) {
        //changing only one channel of the image, in this case, blue
        img3 = change_blue(img, height, width);
        cv::imshow("processed image", img3);
        cv::waitKey(0);
    }
    
    return 0;
}

//defining the functions

//making alternate rows of pixels of the image black
cv::Mat black_out_rows(cv::Mat img, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i % 2 == 0) {
                //this statement accesses the individual pixel values of the image
                //and sets the color values of each channel of every coordinate to 0
                img.at<cv::Vec3b>(i, j)[0] = 0;
                img.at<cv::Vec3b>(i, j)[1] = 0;
                img.at<cv::Vec3b>(i, j)[2] = 0;
            }
        }
    }
    return img;
}

//changing only one channel of the image, in this case, blue
cv::Mat change_blue(cv::Mat img, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i % 2 == 0) {
                //this statement accesses the individual pixel values of the image
                //and sets the color values of each channel of every coordinate to 255 in the blue channel
                img.at<cv::Vec3b>(i, j)[0] = 255;
            }
        }
    }
    return img;
}
