//including the necessary header files
#include <iostream>
//the following header files are from the OpenCV library for C++
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//declaring functions for different operations
Mat black_out_rows(Mat img, int height, int width);
Mat change_blue(Mat img, int height, int width);

int main()
{
    //reading the image and converting it into cv::Mat formatt
    Mat img = imread("../assets/dog.jpeg");
    Mat img2, img3;
    //obtaining the dimensions of the image
    int width = img.size().width;
    int height = img.size().height;
    int choice;
    cout << "Width of the image: " << width << endl;
    cout << "Height of the image: " << height << endl;

    cout << "You have a choice to make - 0 or 1. What will it be? ";
    cin >> choice;
    if (choice == 0)
    {
        //making alternate rows of pixels of the image black
        img2 = black_out_rows(img, height, width);
        //displaying the image on the screen. The image will be displayed until any key is pressed
        imshow("window", img2);
        waitKey(0);
    }
    else if (choice == 1)
    {
        // changing only one channel of the image, in this case, blue
        img3 = change_blue(img, height, width);
        imshow("processed image", img3);
        waitKey(0);
    }

    return 0;
}

//defining the functions

//making alternate rows of pixels of the image black
Mat black_out_rows(Mat img, int height, int width){
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if(i%2==0){
                //this statement accesses the individual pixel values of the image
                //and sets the color values of each channel of every coordinate to 0
                img.at<Vec3b>(i,j)[0]=0;
                img.at<Vec3b>(i,j)[1]=0;
                img.at<Vec3b>(i,j)[2]=0;
            }
        }
    }
    return img;
}

//changing only one channel of the image, in this case, blue
Mat change_blue(Mat img, int height, int width){
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if(i%2==0){
                //this statement accesses the individual pixel values of the image
                //and sets the color values of each channel of every coordinate to 0
                img.at<Vec3b>(i,j)[0]=255;
            }
        }
    }
    return img;
}
