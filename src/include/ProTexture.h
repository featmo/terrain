class ProTexture{
    public:
        int image_width = 0;
        int image_height = 0;
        int resolution = 0;

        const float frequency = 0.5; 
        float luc = 2.5;
        float gain = 0.5;
        float offset = 0;
        int oct = 16;
        float freq_x = 0;
        float freq_y = 0;
 
        void texture_set_width_height(int w, int h);
        void texture_set_resolution(int res);
        float generate_dom_w_fbm(int x, int y, int z, int i);
};