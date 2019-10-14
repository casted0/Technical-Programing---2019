#ifndef GREYSCALE_H
#define GREYSCALE_H
#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <fstream>
#include <sstream>

#define MAX_PIXEL 256

using namespace std;

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
    short * copy_pixels();
    void * write_toFile(short * printed, ofstream & of);

    // Additional functions of the class:

    int * pixel_histogram();        // Pixel histogram
    short * gaussian_blur();        // Gaussian blur
    int * histogram_eq(int * hist); // Histogram equalisation
    short * median_filter();        // Median filtering
};

#endif