#include "greyscale.h"

int main(int argc, char ** argv) {
  
    if(argc != 2){
        cout << "For executing the program ./h3 Name_of_the_file" << endl;
        return 1;
    }

    int pixel_size, height, width;
    bool size_lines = true;
    ifstream image_file;
    string reading, pixel_string = "";

    ///////////////// READING FILE HEIGHT, WIDTH AND PIXELS /////////////////

    image_file.open(argv[1]);

    if (image_file.is_open()) {

        while (!image_file.eof()) {

            if(size_lines){

                getline(image_file, reading); 
                height = atoi(reading.c_str()); 
                cout << endl << "Height of the image: " << height << endl;
                getline(image_file, reading); 
                width = atoi(reading.c_str()); 
                cout << "Width of the image: " << width << endl;
                size_lines = false;

            }else{

                getline(image_file, reading);
                pixel_string = pixel_string + reading;

            }
            
        }

    }else{
        cout << "There was a problem opening that file." << endl;
        return 0;
    }

    /////////////// CONVERTING PIXEL STRING TO SHORT VARIABLES //////////////

    istringstream is(pixel_string);
    short * pixels = new short[width * height];
    short sh_read;
    int i = 0;

    while(is >> sh_read) {

        pixels[i] = sh_read;
        i++;

    }

    ////////////////// BEGIN OF GREYSCALE CLASS FUNCTIONS ///////////////////

    Greyscale image(width * height);

    image.set_pixels(pixels);

    cout << "Size of the image: " << image.get_size() << " Pixels." << endl << endl;

    image.set_pixels(pixels);

    int * pixel_histogram = image.pixel_histogram();

    cout << endl << "Histogram of the base image: " << endl;

    for(int i = 0; i < 256; i++){
        cout << pixel_histogram[i] << " ";
    }
    
    cout << endl;

    // Apply the histogram equalization

    int * equalized_hist = image.histogram_eq(pixel_histogram);

    cout << endl << "Histogram equalized of the base image: " << endl << endl;

    for(int i = 0; i < 256; i++){
        cout << equalized_hist[i] << " ";
    }
    
    cout << endl;

    // Apply the median filtering and print it in another file

    ofstream print_file;
    print_file.open("median_filtering.dat");

    short * median_filtered_image = image.median_filter();

    image.write_toFile(median_filtered_image, print_file);

    print_file.close();
    image_file.close();
    return 0;
    
}


