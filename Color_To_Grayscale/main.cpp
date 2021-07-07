/* Name: Color to Grayscale - Assignment 3 - Submission #1
 * Author: Adam B. Jost
 * Course: CPT-182 Section 80
 * Language: C++
 * Date: 2/9/2021
 * Description: Coverts a color image (.ppm file) to a grayscale image (.ppm file)
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // File input and output streams
    ifstream fin("colorImage.ppm");
    ofstream fout("grayscaleImage.ppm");
    // Check if input file was successfully opened
    if (!fin) {
        cout << "Error - Nonexistent Image (.ppm) File" << endl;
        system("pause");
        return -1;  // Error exit
    }
    // P3 tells the program the image is a .ppm image.
    string magic_number;
    int pixel_per_row, num_rows, color_depth, red, green, blue;
    // Read in values of all of the image details.
    fin >> magic_number >> pixel_per_row >> num_rows >> color_depth;
    //Declare & initialize constant variables
    const string MAGIC_CONSTANT = magic_number;
    const int DEPTH_CONSTANT = color_depth;
    // Begin writing the grayscale image.
    fout << MAGIC_CONSTANT << endl << pixel_per_row << " " << num_rows << endl << DEPTH_CONSTANT << endl;
    // Parse input data. Read in the color depth of each color of each individual pixel.
    while (fin >> red >> green >> blue) {
        red = green = blue = int(0.3 * red + 0.59 * green + 0.11 * blue); //Covert each pixel to grayscale
        fout << red << endl << green << endl << blue << endl; //Write converted values to output file
    }
    //Close files
    fin.close();
    fout.close();
    return 0;
}
