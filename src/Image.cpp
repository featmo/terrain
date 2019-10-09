#include "include/Image.h"

int Image::image_create(std::string file_name, int image_width, int image_height){
    std::vector<int> image_dimension = image_size(image_width, image_height);
    //create netpbm file
    file_object = std::ofstream(file_name);
    file_object << "P3" << "\n" << image_dimension[0]<< " " << image_dimension[1] << "\n" << "255" << std::endl;
    return 0;
}

std::vector<int> Image::image_size(int image_width, int image_height){
    width = image_width;
    height = image_height;
    std::vector<int> image_dimension = {image_width, image_height};
    return image_dimension;
}

int Image::image_set(float color){
    int cout = std::floor(color >= 0.99 ? 255 : color * 256.0);
    int r = std::floor(color >= 0.99 ? 255 : color * 256.0);
    int g = std::floor(color >= 0.99 ? 255 : color * 100.0);
    int b = std::floor(color >= 0.99 ? 255 : color * 0); 

    file_object << r << " " << 20 << " " << 20 << "  " ;

    return 0;
}