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
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


Mat masking(Mat image)
{
   Vec3b grey = Vec3b(230,230,230); //defining masks for the colours which you do not need in the image
   Vec3b white = Vec3b(255,255,255); //so here we want to mask grey and white colours
   
   int height = image.rows; //taking the height and width of the input 'image'
   int width = image.cols;

   Mat transparentImg{image.size(), image.type()}; //creates a new transparent empty image

   for(int i = 0; i < height; i++)
   {
      for(int j = 0; j < width; j++)
      {
         Vec3b x = image.at<Vec3b>(i, j); //getting the pixel rgb values
         if(grey != x && white != x)
         {
            transparentImg.at<Vec3b>(i,j)=x; //write to the new image all other colours except the one's to be ignored
         }
      }
   }
   return transparentImg;
}

int main() 
{
   Mat image; //taking an image matrix
   image = imread("assets/nike.png"); //loading an image
   
   Mat new_img = masking(image);
   imwrite("assets/bg_free.png", new_img);
   imshow("center",new_img);
   waitKey(0);
   destroyAllWindows();
	   
   return 0;
}
