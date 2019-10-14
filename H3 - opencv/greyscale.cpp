#include "greyscale.h"

/*
 Space for implementing greyscale class functions
*/

// Construct the class
Greyscale::Greyscale(int s){
    cout << "Creating the Greyscale instance." << endl;
    this->size = s;
    pixels = new short[s];
}

// Destroy class memory
Greyscale::~Greyscale(){

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

// Plot the image
vector<int> Greyscale::pixel_histogram(){

    vector<int> pixel_counter;
    short * pixels = this->pixels;
    short aux;

    for(int i = 0; i < 256; i++){
        pixel_counter.push_back(0);
    }

    for(int i = 0; i < this->size; i++){
        aux = pixels[i];
        pixel_counter[aux]++;
    }

    return pixel_counter;

}
