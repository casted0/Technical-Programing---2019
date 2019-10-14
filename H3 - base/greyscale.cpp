#include "greyscale.h"

/*
 Space for implementing greyscale class functions
*/

// Auxiliar function for median_filtering
short med_value(short s1, short s2, short s3);

// Construct the class
Greyscale::Greyscale(int s){
    cout << "Creating the Greyscale instance." << endl;
    this->size = s;
    pixels = new short[s];
}

// Destroy class memory
Greyscale::~Greyscale(){
    delete[] this->pixels;
}

// Get size of the pixel array
int Greyscale::get_size(){
    return this->size;
}

// Set pixels of the pixel array
void Greyscale::set_pixels(const short * pixel_list){
    for(int i = 0; i < this->size; i++){
        this->pixels[i] = pixel_list[i];
    }
}

// Get the array of pixels
short * Greyscale::get_pixels(){
    return this->pixels;
}

// Return a copy of the pixel array
short * Greyscale::copy_pixels(){
    short * copy = new short[this->size];
    for(int i = 0; i < this->size; i++){
        copy[i] = this->pixels[i];
    }
    return copy;
}

// Write a short array into a file
void * Greyscale::write_toFile(short * printed, ofstream & of){
    of << "512" << endl << "512" << endl;
    for(int i = 1; i <= this->size; i++){
        of << printed[i-1] << " ";
        if(!(i % 512)){
            of << endl;
        }
    }
}

// Returns the data of the histogram in an int * array
int * Greyscale::pixel_histogram(){

    int * pixel_counter = new int[MAX_PIXEL];
    short * pixels = this->pixels;
    short aux;

    for(int i = 0; i < 256; i++){
        pixel_counter[i] = 0;
    }

    for(int i = 0; i < this->size; i++){
        aux = pixels[i];
        pixel_counter[aux]++;
    }

    return pixel_counter;

}

// Returns the image pixels after applying a Gaussian Blur effect
short * Greyscale::gaussian_blur(){





}

int * Greyscale::histogram_eq(int * hist){

    int * new_hist = new int[256];

    new_hist[0] = hist[0];
 
    for(int i = 1; i < 256; i++)
    {
        new_hist[i] = hist[i] + new_hist[i-1];
    }

    return new_hist;
}

// Returns an array of pixels after applying a median_filter
short * Greyscale::median_filter(){

    int index_1 = 0, index_2 = 1, index_3 = 2;
    short p1, p2, p3;
    short * new_pixels = this->copy_pixels();

    for(int i = 0; i < this->size; i++, index_1++, index_2++, index_3++){

        p1 = this->pixels[index_1];
        p2 = this->pixels[index_2];
        p3 = this->pixels[index_3];

        new_pixels[i] = med_value(p1, p2, p3);

    }

    return new_pixels;

}

// Auxiliary function for median_filtering
short med_value(short s1, short s2, short s3){

    if((s1 < s2 && s1 > s3) || (s1 > s2 && s1 < s3)){
        return s1; // 2 3 1 , 3 2 4
    }else if((s2 < s1 && s2 > s3) || (s2 > s1 && s2 < s3)){
        return s2; // 3 2 1 , 1 2 3
    }else{
        return s3;
    }
}