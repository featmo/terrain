#include <iostream>
#include <cmath>
extern "C"
{
    #include "include/stb_perlin.h"
}

#include "include/PerlinNoise.hpp"
#include "Image.h"
#include "include/noise.hpp"


#define STB_PERLIN_IMPLEMENTATION

#define IMAGE_W 500
#define IMAGE_H 500

/**VARIABLES**/
    const float frequency = 1.5; 
    float luc = 2.5;
    float gain = 0.5;
    float offset = 0;
    int oct = 16;
    const float freq_x = (float) IMAGE_W/frequency;
    const float freq_y = (float) IMAGE_H/frequency;

/**Generate domain warp on noise function**/
float generate(int x, int y, int z){
    float g_x = std::fabs( stb_perlin_fbm_noise3(x/freq_x, y/freq_y, z, luc, gain, oct) );
    float g_y = std::fabs( stb_perlin_fbm_noise3
        (
        x/freq_x + 8.0, 
        y/freq_y + 8.0,
        z, 
        luc, 
        gain, 
        oct) 
    );
    float f_x = std::fabs( stb_perlin_fbm_noise3(x/freq_x, y/freq_y, z, luc, gain, oct) );
    float f_y = std::fabs( stb_perlin_fbm_noise3
        (
        x/freq_x + 2.0*g_x, 
        y/freq_y + 2.0*g_y,
        z, 
        luc, 
        gain, 
        oct) 
    );

    return std::fabs( stb_perlin_fbm_noise3(x/freq_x + f_x, y/freq_y + f_y, z, luc, gain, oct) );

}

int main(){

    Image img = Image();
    img.Image_create("image.ppm", IMAGE_W,IMAGE_H);

    std::cout << "image res: "<< img.width <<std::endl;

    for(int y = 0; y < IMAGE_W; y++){
        for(int x = 0; x < IMAGE_H; x++){
                
            //stb_noise lib
            //float n = std::fabs( stb_perlin_fbm_noise3(0.5, 0.5, 0, luc, gain, oct) );

            float p = generate(x, y, 0);
            img.Image_set(p);
        
        }

        img.file_object << std::endl;
    }
        
    return 0;
}