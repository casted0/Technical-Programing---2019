#include "greyscale.h"

void drawHist(const vector<int>& data, Mat3b& dst, int binSize, int height);

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
                cout << "Height of the image: " << height << endl;
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
    Mat3b plot;

    image.set_pixels(pixels);

    cout << "Size of the image: " << image.get_size() << " Pixels." << endl;

    image.set_pixels(pixels);

    vector<int> pixel_histogram = {0, 3, 4, 5, 6, 7, 8, 9};

    /*for(int i = 0; i < 256; i++){
        cout << pixel_histogram[i] << " ";
    }*/
    
    cout << endl;

    ////////////////// PLOT THE HISTOGRAM ///////////////////

    drawHist(pixel_histogram, plot, 3, 0);
    imshow("Histogram", plot);
    waitKey();

    image_file.close();
    return 0;
    
}


    ////////////////////// DRAW HIST FUNCTION /////////////////////////


void drawHist(const vector<int>& data, Mat3b& dst, int binSize, int height){

    int max_value = *max_element(data.begin(), data.end());
    int rows = 0;
    int cols = 0;

    if (height == 0) {

        rows = max_value + 10;

    } else { 

        rows = max(max_value + 10, height);
        
    }

    cols = data.size() * binSize;

    dst = Mat3b(rows, cols, Vec3b(0,0,0));

    for (int i = 0; i < data.size(); ++i)
    {
        int h = rows - data[i];
        rectangle(dst, Point(i*binSize, h), Point((i + 1)*binSize-1, rows), (i%2) ? Scalar(0, 100, 255) : Scalar(0, 0, 255), CV_FILLED);
    }

}
