#include "image_export.h"

void init_module()
{
    Image::objs_cnt = 0;
    // std::cout << "C++: init_module() called." << std::endl;
}

ObjID new_image()
{
    Image::objs[++Image::objs_cnt] = std::make_shared<Image>();
    return Image::objs_cnt;
}

void del_image(ObjID id)
{
    if(Image::objs.count(id)) Image::objs.erase(id);
}

void set_image_data(ObjID id, uint32_t width, uint32_t height, uint8_t *data)
{
    if(!Image::objs.count(id)) return;
    Image::objs[id]->set_data(width, height, data);
}

void get_image_data(ObjID id, uint8_t *data)
{
    if(!Image::objs.count(id)) return;
    Image::objs[id]->get_data(data);
}

void inverse_image(ObjID id)
{
    if(!Image::objs.count(id)) return;
    Image::objs[id]->inverse_image();
}

void print_image_info(ObjID id)
{
    if(!Image::objs.count(id)) return;
    Image::objs[id]->print_info();
}

void flip_image(uint32_t width, uint32_t height, uint8_t *data)
{
    if(data == nullptr) return;

    auto idx = [width](uint32_t h, uint32_t w) -> uint32_t {
        return h * width + w;
    };

    for(uint32_t h = 0; h < height; h ++) {
        uint32_t half_width = width >> 1;
        for(uint32_t w = 0; w < half_width; w ++) {
            uint32_t target = width - w - 1;
            // swap (h,w) and (h,target)
            uint32_t l = idx(h,w) * 3, r = idx(h,target) * 3;
            for(uint32_t t = 0; t < 3; t ++)
                std::swap(data[l + t], data[r + t]);
        }
    }
}