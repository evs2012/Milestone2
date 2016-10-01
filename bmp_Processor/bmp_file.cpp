#include "bmp_file.h"

/**< Compares colors within the accumulator struct for sort*/
bool ColorCompare(accumulator a, accumulator b)
{
    return ((unsigned int)a.color < (unsigned int)b.color);
}

bmp_file::bmp_file(){/**< Default Constructor */}
bmp_file::~bmp_file(){/**< Default Destructor */}

/**< The following functions extract data from the bitmap header */
unsigned long bmp_file::getFileSize(){return get32(2);}
unsigned long bmp_file::getStartOfBitmap(){return get32(10);}
unsigned long bmp_file::getWidth(){return get32(18);}
unsigned long bmp_file::getHeight(){return get32(22);}
unsigned long bmp_file::getNumberOfColorsInPalette(){return get32(50);}

/**< Returns the pixel data located in the specified file byte */
unsigned char bmp_file::getPixel(int index) {
    return fileData[index];
}

/**< Writes a byte to the specified pixel */
void bmp_file::setPixel(int index, unsigned char byte) {
    fileData[index] = byte;
}

/**< Extracts a 32-bit unsigned long value from fileData beginning with element LSBindex */
unsigned long bmp_file::get32(int LSBindex) {
    unsigned long temp = 0;
    for (int i = 3; i >=0; --i) {
        temp = (fileData[LSBindex+i] | temp << 8);
        temp |= fileData[LSBindex + i];
    }
    return temp;
}

/**< Creates an instance of bmp_file containing the specified file */
bmp_file::bmp_file(char* filepath) {
    std::ifstream infile;
    infile.open(filepath, std::ifstream::in | std::ifstream::binary);
    if (!infile){
        std::cout << "\nFile " << filepath << " not found.";
        return;
    } else {
        std::cout << "\nOpening " << filepath << "...";
    }
    char * buffer = new char [1];
    while (!infile.eof())
    {
        infile.read(buffer, 1);
        fileData.push_back(*buffer);
    }
    //get rid of extra byte
    fileData.pop_back();
    /// TODO: Maria copy this vector into the other three: IO_fileOutput, HE_fileOutput, and SB_output
}

/**< Writes the data in the bmp_file instance to the specified file */
void bmp_file::writeToNewFile(char* filepath) {
    std::ofstream outFile;
    outFile.open(filepath, std::ofstream::out | std::ofstream::binary);
    if (!outFile){
        std::cout << "\nUnable to write to " << filepath << ".";
        return;
    } else {
        std::cout << "\nWriting " << filepath << "...";
    }
    char * buffer = new char [1];
    for (unsigned int i = 0; i < fileData.size(); i++) {
        *buffer = fileData[i];
        outFile.write(buffer,1);
    }
}

void bmp_file::writeIOtoNewFile(char* filepath) {
    std::ofstream outFile;
    outFile.open(filepath, std::ofstream::out | std::ofstream::binary);
    if (!outFile){
        std::cout << "\nUnable to write to " << filepath << ".";
        return;
    } else {
        std::cout << "\nWriting " << filepath << "...";
    }
    char * buffer = new char [1];
    for (unsigned int i = 0; i < IO_fileOutput.size(); i++) {
        *buffer = IO_fileOutput[i];
        outFile.write(buffer,1);
    }
}

void bmp_file::writeHEtoNewFile(char* filepath) {
    std::ofstream outFile;
    outFile.open(filepath, std::ofstream::out | std::ofstream::binary);
    if (!outFile){
        std::cout << "\nUnable to write to " << filepath << ".";
        return;
    } else {
        std::cout << "\nWriting " << filepath << "...";
    }
    char * buffer = new char [1];
    for (unsigned int i = 0; i < HE_fileOutput.size(); i++) {
        *buffer = HE_fileOutput[i];
        outFile.write(buffer,1);
    }
}

void bmp_file::writeSBtoNewFile(char* filepath) {
    std::ofstream outFile;
    outFile.open(filepath, std::ofstream::out | std::ofstream::binary);
    if (!outFile){
        std::cout << "\nUnable to write to " << filepath << ".";
        return;
    } else {
        std::cout << "\nWriting " << filepath << "...";
    }
    char * buffer = new char [1];
    for (unsigned int i = 0; i < SB_fileOutput.size(); i++) {
        *buffer = SB_fileOutput[i];
        outFile.write(buffer,1);
    }
}

/**< Outputs header data to the console using the std::cout stream */
void bmp_file::printData() {
    std::cout << "\nHeader data:";
    std::cout << "\n  Filesize: " << getFileSize();
    std::cout << "\n  Offset: " << getStartOfBitmap();
    std::cout << "\n  Width: " << getWidth();
    std::cout << "\n  Height: " << getHeight();
    std::cout << "\n  Vector Size: " << fileData.size();
}

void bmp_file::imageOverlay(bmp_file overlayImage, char * outFile)
{
    /// TODO: Imran Make this write to IO output vector and not modify original image vector

    unsigned long inOffset = this->getStartOfBitmap();
    unsigned long ovOffset = overlayImage.getStartOfBitmap();
    unsigned long pixels = this->getWidth() * this->getHeight();
    if (pixels != (overlayImage.getWidth() * overlayImage.getHeight())){
        std::cout << "\nImages are not the same size.";
        return;
    }
    for (unsigned long i = 0; i < pixels; i++){
        if (overlayImage.getPixel(ovOffset + i) == 0x00)
            this->setPixel(inOffset + i, 0xFF);
    }
    this->writeToNewFile(outFile);
}

/**< Gets count of all colors used [0 to 255] and then calculates a new color for each color, overwrites
     this bitmap to the new colors pixel by pixel and out puts the resulting bitmap to filePath */
void bmp_file::histogram_equalization() {
    ///Creating histogram counting vector
    std::vector <accumulator> histogram;

    /// Populate histogram with gray scale colors, each count at 0
    for (int i = 0; i < 256; i ++) {
        accumulator *temp = new accumulator(i);
        histogram.push_back(*temp);
    }

    /// Populate the histogram with data from the bitmap, increment the appropriate counter for each pixel
    for( unsigned int i = getStartOfBitmap(); i < fileData.size(); i++) {
        for (unsigned int j = 0; j < histogram.size(); j++)                 /// loop through file
        {
            if ( (unsigned int)histogram[j].color == (unsigned int)fileData[i] )                        /// if we have this color increment the count
            {
                histogram[j].counter++;
                /// found, move on to next pixel
                break;
            }
        }
    }

    /// Sort by color 0 to 255
    std::sort(histogram.begin(), histogram.end(), ColorCompare);

    /// i = 0 condition: cumulative count = count of color 0
    histogram[0].cCounter = histogram[0].counter;
    for(unsigned int i = 1; i < histogram.size(); i++) {
        /// Each cumulative count is the colors count plus the previous cumulative count
        histogram[i].cCounter = histogram[i].counter + histogram[i-1].cCounter;
    }

    for(unsigned int i = 0; i < histogram.size(); i++) {
        /// calculate cumulative percent
        histogram[i].cPercent = (double)histogram[i].cCounter / (double)histogram[histogram.size()-1].cCounter;
    }

    /// Histogram equalization
    for(unsigned int i = 0; i<histogram.size(); i++) {
        /// New color = floor cumulative percent * number of available colors
        histogram[i].newColor = (uint8_t)floor(histogram[i].cPercent * 255) ; ///new color = percentile of cumulative * number of colors
    }

    /// write the Histogram Equalized data to the output vector.
    for(unsigned int i = getStartOfBitmap(); i < HE_fileOutput.size(); i++) {
        for (unsigned int j = 0; j < histogram.size(); j++)
        {
            if ((uint8_t)fileData[i] == histogram[j].color)
            {
                HE_fileOutput[i] = histogram[j].newColor;
                /// move to next pixel to only write new color once
                break;
            }
        }
    }
}

/**< modify the image's brightness and contrast using the values given.
    The brigness is a straight multiplier where 1 has no effect on the image, higher makes it brighter, lower to 0 makes it darker
    The contrast gives the spread of distribution. 0 to 127 where 127 means it will spread the distribution across 0 to 255 */
void bmp_file::sliderBarAdjustment(double brightness, int contrast, char * outpath) {
    /// Brightness adjustment
    // change the color, if it gets higher than 255 make it 255
    for (unsigned int i = getStartOfBitmap(); i < fileData.size(); i++) {
        if (fileData[i] * brightness > 255) {
            SB_fileOutput[i] = 255;
        } else {
            SB_fileOutput[i] = (unsigned char)(fileData[i] * brightness);
        }
    }

    /// Contrast adjustment
    // find the furthest shade away from the center shade
    int furthestDistance = 0;
    for (unsigned int i = getStartOfBitmap(); i < SB_fileOutput.size(); i++) {
        if (furthestDistance < abs(SB_fileOutput[i] - 128))
        {
            furthestDistance = abs(SB_fileOutput[i] - 128);
        }
    }

    // scale shades so that furthest becomes contrast param away from center
    // Equation: newShade = 128 +or- ScalingFactor * DistanceFrom128
    double scalingFactor = contrast / furthestDistance;
    for (unsigned int i = getStartOfBitmap(); i < SB_fileOutput.size(); i++) {
        if(SB_fileOutput[i] < 128) {
            SB_fileOutput[i] = (unsigned char)(128 - scalingFactor * abs(SB_fileOutput[i] - 128));
        } else {
            SB_fileOutput[i] = (unsigned char) (128 + scalingFactor * abs(SB_fileOutput[i] - 128));
        }
    }

    this->writeSBtoNewFile(outpath);

}

unsigned char * bmp_file::getFileData()
{
    unsigned char *data = reinterpret_cast<unsigned char*>(this->fileData.data());

    return data;
}
