# Project Terrain
A tool for generating heightmaps, it implements FBM to generate the initial noise maps and currently has domain warping to create more intricate effects, this is then exported as a PBM file.

It uses stb_noise from [Nothing's STB single file repo](https://github.com/nothings/stb) to generate the noise texture and [Inigo Quilez's](https://www.iquilezles.org/www/articles/warp/warp.htm) method for domain warping, he made it surprisingly simple to understand and I'd highly recommend his article on the subject.



Built in C++ and compiled with gcc version 9.1.0
