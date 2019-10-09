#include <filesystem>
#include <iostream>
#include <SDL.h>

#include "include/bitmap_image.hpp"
#include "include/Image.h"
#include "include/ProTexture.h"

namespace fs = std::filesystem;

#define IMAGE_W 480
#define IMAGE_H 480


void save_texture(){
    int RES_H = 1024;
    int RES_W = 1024;

    bitmap_image bit_image(RES_W, RES_H);
    std::string path = "../out_images/out.bmp"; 

    ProTexture protxt = ProTexture();
    protxt.texture_set_resolution(RES_W);
         
    //img.image_create("../out_images/image.ppm", LOW_W, LOW_H);
    //std::cout << "image res: "<< protxt.resolution <<std::endl;
    
    for(int y = 0; y < RES_H; y++){
        for(int x = 0; x < RES_W; x++){      
            float p = protxt.generate_dom_w_fbm(x,y,0,1);
            //img.image_set(p);

            int c_out = std::floor(p >= 0.99 ? 255 : p * 256.0);
            bit_image.set_pixel(x, y, c_out, c_out, c_out);   
        }
    }
    bit_image.save_image(path);   
    
}
int render_map(int x, int y, int z, int res){

    ProTexture protxt = ProTexture();
    protxt.texture_set_resolution(res);
    int c_out = 0;      

    float p = protxt.generate_dom_w_fbm(x,y,0,1) * 1.5;
    c_out = std::floor(p >= 0.99 ? 255 : p * 256.0);
    return c_out;        

}

int main(int argc, char * argv[]){
    fs::create_directory("../out_images");

    /**Initialize window object**/
    SDL_Window *app_window;
    SDL_Renderer *app_render;

    //SDL_Surface *surface = SDL_LoadBMP("../out_images/out.bmp");
    //SDL_Texture *texture = SDL_CreateTextureFromSurface(app_render, surface);
    //SDL_FreeSurface(surface);

    //initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("Unable to Initialize: %s", SDL_GetError());
        return 1;
    }
    else{
        /**Create Window**/
        app_window = SDL_CreateWindow(
            "Terrain",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            IMAGE_W,
            IMAGE_H,
            SDL_WINDOW_OPENGL
            );
        app_render = SDL_CreateRenderer(app_window, -1, SDL_RENDERER_ACCELERATED);
    
        //Check window and renderer null
        if(app_window == 0){ std::cout << "Could not create window" << std::endl; }
        if(app_render == 0){
            std::cout << SDL_GetError() << std::endl;
            SDL_DestroyWindow(app_window);
            SDL_DestroyRenderer(app_render);
            SDL_Quit();
        }

        bool quit = false;
        SDL_Event e;
        SDL_SetRenderDrawColor(app_render, 0, 0, 0, 255);
        SDL_RenderClear(app_render);
        
        /**keep window open till quit**/
        while(!quit){
            //SDL_RenderCopy(app_render, texture, NULL, NULL);
            while( SDL_PollEvent(&e) ) {
                if (e.type == SDL_QUIT) { quit = true; }
                
                if (e.type == SDL_KEYDOWN){
                /**Generate Map in Viewport**/     
                    for(int j = 0; j < IMAGE_H; j+=3){
                        for(int i = 0; i < IMAGE_W; i+=3){

                            //key events for rendering
                            if(e.key.keysym.sym == SDLK_a){
                                int color = render_map(i,j,0, IMAGE_H);
                                SDL_SetRenderDrawColor(app_render, color, color, color, 255);
                                SDL_RenderDrawPoint(app_render, i, j);
                            }
                            
                        }
                    }
                    //save result
                    if(e.key.keysym.sym == SDLK_s){ save_texture(); }                 
                }
            }           
            SDL_RenderPresent(app_render);     
        }        
    }

    //Clean up
    //SDL_DestroyTexture(texture);
    SDL_DestroyWindow(app_window);
    SDL_DestroyRenderer(app_render);
    SDL_Quit();
        
    return 0;
}