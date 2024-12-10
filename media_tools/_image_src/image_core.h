#ifndef IMAGE_CORE_H
#define IMAGE_CORE_H

#include "tools.h"

class Image
{
public:
    static std::unordered_map<ObjID, std::shared_ptr<Image>> objs;
    static ObjID objs_cnt;

public:
    Image();
    virtual ~Image();

public:
    void set_data(uint32_t width, uint32_t height, uint8_t *data);
    void get_data(uint8_t *data);
    void inverse_image();
    void print_info() const;

protected:
    uint32_t width, height;
    std::shared_ptr<uint8_t[]> data;
};

#endif