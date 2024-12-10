.PHONY: all _image_src clean

include $(COMMON_MAKE_PATH)/Makein

all: libimage.so

libimage.so: _image_src
	$(CXX) -shared -o libimage.so _image_src/*.o

_image_src:
	$(MAKE) -C _image_src

clean:
	$(MAKE) -C _image_src clean
	rm -rf libimage.so