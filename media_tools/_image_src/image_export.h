#ifndef IMAGE_EXPORT_H
#define IMAGE_EXPORT_H

#include "tools.h"
#include "image_core.h"

extern "C" void  init_module();
extern "C" ObjID new_image();
extern "C" void  del_image(ObjID id);
extern "C" void  set_image_data(ObjID id, uint32_t width, uint32_t height, uint8_t *data);
extern "C" void  get_image_data(ObjID id, uint8_t *data);
extern "C" void  inverse_image(ObjID id);
extern "C" void  print_image_info(ObjID id);
extern "C" void  flip_image(uint32_t width, uint32_t height, uint8_t *data);

#endif