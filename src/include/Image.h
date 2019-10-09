#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#ifndef CMATH_H
#define CMATH_H
#include <cmath>
#endif

class Image{
    public:
        int width;
        int height;
        std::string file_name;
        std::ofstream file_object;

        int image_create(std::string file_name, int image_width, int image_height);
        std::vector<int> image_size(int image_width, int image_height);

        /**
         * Set color of pixel
         * use with for loop
         * 
         * **** psuedo code *****
         * for i is less than n
         *      image.set(some_value)
         * 
         * values are converted from 0 - 1 to 0 - 255
         * 
         * 
        **/
        int image_set(float color);


};
