__all__ = ["BP"]

import ctypes

def BP(bytes: bytearray):
    return ctypes.cast(bytes, ctypes.POINTER(ctypes.c_uint8))