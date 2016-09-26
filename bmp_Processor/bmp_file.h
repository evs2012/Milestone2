#ifndef BMP_FILE_H
#define BMP_FILE_H

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <math.h>

class bmp_file
{    
    bmp_file();                                                         /**< Default constructor */
    virtual ~bmp_file();                                                /**< Default destructor */
    bmp_file(char* filepath);                                           /**< Creates an instance of bmp_file containing the specified file */

    void writeToNewFile(char* filepath);                                /**< Writes the data in the bmp_file instance to the specified file */
    void writeIOtoNewFile(char* filepath);                              /**< Writes the Image Overlay output to the specified file */
    void writeHEtoNewFile(char* filepath);                              /**< Writes the Histogram Equalization output to the specified file */
    void writeSBtoNewFile(char* filepath);                              /**< Writes the Slider Bar output to the specified file */
    void histogram_equalization();                                      /**< Histogram equalizes the image and writes it to the Output vector */
    void imageOverlay(bmp_file overlayImage, char * outFile);           /**< Takes the overlay image as a Bmp_file object and overlays it over this bmp_file */
    void sliderBarAdjustment(double brightness, int contrast);          /**< Takes the numerical inputs from the slider bars and edits the image */
    unsigned long getFileSize();                                        /**< Extracts the file size from the bitmap header */
    unsigned long getStartOfBitmap();                                   /**< Extracts the image offset from the bitmap header */
    unsigned long getWidth();                                           /**< Extracts the image width from the bitmap header */
    unsigned long getHeight();                                          /**< Extracts the image height from the bitmap header */
    unsigned long getNumberOfColorsInPalette();                         /**< Extracts the bits/px value from the bitmap header */
    void printData();                                                   /**< Outputs header data to the console using the std::cout stream */

    unsigned char getPixel(int index);                                  /**< Returns the pixel data located in the specified file byte */
    void setPixel(int index, unsigned char byte);                       /**< Writes a byte to the specified pixel */

private:
    unsigned long get32(int LSBindex);                                  /**< Extracts a 32-bit unsigned long value from fileData beginning with element LSBindex */
    std::vector<unsigned char> fileData;                                /**< Contains the original bitmap data */
    std::vector<unsigned char> IO_fileOutput;                           /**< Contains the resulting bitmap data after the IO is performed */
    std::vector<unsigned char> HE_fileOutput;                           /**< Contains the resulting bitmap data after HE*/
    std::vector<unsigned char> SB_fileOutput;                           /**< Contains the resulting bitmap data after Slider bars adjust contrast and brightness */
};

/// used to count the occurences of colors and then calculate the new color in Histogram Equalization
struct accumulator
{
    public:
        accumulator(uint8_t _color)
        {
            color = _color;
            counter = 0;
        }
        int counter;
        int cCounter;   ///cumulative count
        uint8_t color;
        uint8_t newColor;
        double cPercent;       /// cumulative percent

    private:

};

#endif // BMP_FILE_H
