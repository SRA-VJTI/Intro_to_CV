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
#include "2_build_systems.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Create a black image
    Mat image = Mat::zeros( 400, 400, CV_8UC3 );

    // Write some Text
    putText(image, "Hello World :)", Point(15, 200),
        FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 0), 3);

    imshow("Hello World", image);
    
    //display an image from the $PROJECT_SOURCE_DIR/assets/images/b&w.PNG
    Mat img = imread("PROJECT_SOURCE_DIR/assets/images/bcci.png", IMREAD_COLOR);
    imshow("b&w", img);

    // Wait for a keystroke in the window
    waitKey(0);
    return 0;
}