.PHONY: all clean

include $(COMMON_MAKE_PATH)/Makein

all: image_core.o image_export.o

image_core.o: image_core.cpp image_core.h
	$(CXX) $(CXXFLAGS) -c image_core.cpp -o image_core.o

image_export.o: image_export.cpp image_export.h
	$(CXX) $(CXXFLAGS) -c image_export.cpp -o image_export.o

clean:
	rm -rf *.o