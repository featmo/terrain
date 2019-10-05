#include <fstream>
#include <string>
#include <vector>
#include <cmath>
class Image{
    public:
        int width;
        int height;
        std::string file_name;
        std::ofstream file_object;

        int Image_create(std::string file_name, int image_width, int image_height);
        std::vector<int> Image_size(int image_width, int image_height);

        int Image_set(float color);


};
