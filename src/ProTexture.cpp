#ifndef CMATH_H
#define CMATH_H
#include <cmath>
#endif

#include "include/ProTexture.h"
extern "C"
{
    #include "include/stb_perlin.h"
}

#ifndef STB_PERLIN_IMPLEMENTATION
#define STB_PERLIN_IMPLEMENTATION
#endif

void ProTexture::texture_set_width_height(int w, int h){
    freq_x = w/frequency;
    freq_y = h/frequency;

    image_width = w;
    image_height = h;
}
void ProTexture::texture_set_resolution(int res){
    resolution = res;
    freq_x = resolution/frequency;
    freq_y = resolution/frequency;
}
float ProTexture::generate_dom_w_fbm(int x, int y, int z, int i){
    float g_x = std::fabs( stb_perlin_fbm_noise3(x/freq_x, y/freq_y, z, luc, gain, oct) );
    float g_y = std::fabs( stb_perlin_fbm_noise3
        (
        x/freq_x + 1.0, 
        y/freq_y + 1.0,
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

    //return domain warp
    if(i == 1)
        return std::fabs( stb_perlin_fbm_noise3(x/freq_x + g_x, y/freq_y + g_y, z, luc, gain, oct) );

    if(i == 2)
        return std::fabs( stb_perlin_fbm_noise3(x/freq_x + f_x, y/freq_y + f_y, z, luc, gain, oct) );  
    
    return std::fabs( stb_perlin_fbm_noise3(x/freq_x, y/freq_y, z, luc, gain, oct) );

}