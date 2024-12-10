__all__ = [
    "_init_module",
    "_new_image",
    "_del_image",
    "_set_image_data",
    "_get_image_data",
    "_inverse_image",
    "_print_image_info",
    "_flip_image"
]

import ctypes, os
from ctypes import POINTER, c_uint8, c_uint32, c_uint64
from media_tools._basic import *

ObjID = c_uint32

current_path = os.path.dirname(os.path.abspath(__file__))
so_path = os.path.join(current_path, 'libimage.so')
libimage = ctypes.cdll.LoadLibrary(so_path)

_init_module = libimage.init_module
_init_module.argtypes = ()
_init_module.restype = None

_new_image = libimage.new_image
_new_image.argtypes = ()
_new_image.restype = ObjID

_del_image = libimage.del_image
_del_image.argtypes = (ObjID,)
_del_image.restype = None

_set_image_data = libimage.set_image_data
_set_image_data.argtypes = (ObjID, c_uint32, c_uint32, POINTER(c_uint8))
_set_image_data.restype = None

_get_image_data = libimage.get_image_data
_get_image_data.argtypes = (ObjID, POINTER(c_uint8))
_get_image_data.restype = None

_inverse_image = libimage.inverse_image
_inverse_image.argtypes = (ObjID,)
_inverse_image.restype = None

_print_image_info = libimage.print_image_info
_print_image_info.argtypes = (ObjID,)
_print_image_info.restype = None

_flip_image = libimage.flip_image
_flip_image.argtypes = (c_uint32, c_uint32, POINTER(c_uint8))
_flip_image.restype = None