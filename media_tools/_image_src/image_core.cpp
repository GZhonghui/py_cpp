#include "image_core.h"

std::unordered_map<ObjID, std::shared_ptr<Image>> Image::objs;
ObjID Image::objs_cnt;

Image::Image()
{
    // std::cout << "C++: Image::Image() called." << std::endl;
}

Image::~Image()
{
    // std::cout << "C++: Image::~Image() called." << std::endl;
}

void Image::set_data(uint32_t width, uint32_t height, uint8_t *data)
{
    this->width = width, this->height = height;

    uint32_t bytes_size = width * height * 3;
    uint8_t *raw_ptr = new uint8_t[bytes_size];
    this->data = std::shared_ptr<uint8_t[]>(raw_ptr, std::default_delete<uint8_t[]>()); // C++ 17

    memcpy(this->data.get(), data, bytes_size);

    /*
    uint64_t sum = 0;
    for(uint32_t i = 0; i < bytes_size; i ++) {
        sum += this->data[i];
    }
    */

    // std::cout << "C++: Sum(image) = " << sum << std::endl;
}

void Image::get_data(uint8_t *data)
{
    if(data == nullptr || this->data == nullptr) return;

    uint32_t bytes_size = width * height * 3;
    memcpy(data, this->data.get(), bytes_size);
}

void Image::inverse_image()
{
    if(data == nullptr) return;

    uint32_t bytes_size = width * height * 3;
    for(uint32_t i = 0; i < bytes_size; i ++) {
        data[i] = UINT8_MAX - data[i];
    }
}

void Image::print_info() const
{
    std::cout << "C++: Image of (" << width << ", " << height << ")" << std::endl;
}