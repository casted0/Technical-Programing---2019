#ifndef GREYSCALE_H
#define GREYSCALE_H
#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <fstream>
#include <sstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <algorithm>

using namespace std;
using namespace cv;

class Greyscale {
private:
    int size;                // Size of the array, in this exercise i.e 512*512.
    short * pixels;          // Array of pixels, created with 'new', from 0-255.
public:                      // Basic functions of the class, set, get, etc.
    Greyscale(int s);        // Greyscale constructor
    ~Greyscale();
    void set_pixels(const short * pixel_list);
    int get_size();
    short * get_pixels();
    // Additional functions of the class:
    vector<int> pixel_histogram(); // Pixel histogram
    // Gaussian blur
    // Histogram equalisation
    // Median filtering
};

#endif