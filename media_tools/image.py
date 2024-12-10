import os, PIL.Image
import numpy as np
from media_tools._basic import *
from media_tools._image_importer import *

_init_module()

class Image:
    def __init__(self, width: int, height: int):
        self._id = _new_image()
        self.width = width
        self.height = height

        self.bytes = np.zeros(self.width * self.height * 3, dtype=np.uint8).tobytes()
        _set_image_data(self._id, self.width, self.height, BP(self.bytes))

    def __del__(self):
        _del_image(self._id)

    def open(self, image_path: str):
        if os.path.exists(image_path) and os.path.isfile(image_path):
            image = PIL.Image.open(image_path)
            if image.mode != "RGB":
                image = image.convert("RGB")
            self.bytes = image.tobytes()
            self.width, self.height = image.width, image.height
            _set_image_data(self._id, image.width, image.height, BP(self.bytes))

    def save(self, save_path: str):
        image = PIL.Image.frombytes("RGB", (self.width, self.height), self.bytes)
        image.save(save_path)

    def inverse(self):
        _inverse_image(self._id)
        _get_image_data(self._id, BP(self.bytes))

    def flip(self):
        _flip_image(self.width, self.height, BP(self.bytes))
        _set_image_data(self._id, self.width, self.height, BP(self.bytes))

    def print(self):
        _print_image_info(self._id)