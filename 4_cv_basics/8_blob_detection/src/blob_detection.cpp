#include <opencv2/opencv.hpp>
#include <iostream>

/*
    Specifying Namespaces
    Namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it. 
*/

using namespace std;
using namespace cv;

/*
    Function to find median of a set of pixels

    Purpose:
    -----
    Takes a vector of pixels of one channel and outputs the median of the values.

    Input Args:
    -----
    vector<double> vec: A dynamic array with data type double.

    Returns:
    -----
    Median value
*/

double median(vector<double> vec)
{
    int size = vec.size();
    if (size == 0)
    {
        return 0; // Handle empty vector case
    }
    sort(vec.begin(), vec.end());
    if (size % 2 == 0)
    {
        // Even number of elements, take average of middle 2
        return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
    }
    else
    {
        // Odd number of elements, take middle element
        return vec[size / 2];
    }
}

/*
    Function to find median of each channel

    Purpose:
    -----
    Finds the median value of each channel in a given image

    Input Args:
    -----
    Mat img: An n-dimensional numerical array that represents an image.

    Returns:
    -----
    A tuple containing median values for each channel.
*/

tuple<double, double, double> getMedianPixelValues(Mat img)
{
    // Initialize vectors to store the pixel values of each color channel
    vector<double> hue_pixels;
    vector<double> saturation_pixels;
    vector<double> value_pixels;

    // Iterate over the rows and columns of the image
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            // Access the pixel value at (i, j)
            Vec3b pixel = img.at<Vec3b>(i, j);

            // Add the pixel values to the corresponding vectors
            hue_pixels.push_back(pixel[0]);
            saturation_pixels.push_back(pixel[1]);
            value_pixels.push_back(pixel[2]);
        }
    }

    // Calculate the median of each color channel
    double hue_median = median(hue_pixels);
    double saturation_median = median(saturation_pixels);
    double value_median = median(value_pixels);

    // Return the median values as a tuple
    return make_tuple(hue_median, saturation_median, value_median);
}
