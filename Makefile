.PHONY: all media_tools clean

export COMMON_MAKE_PATH = $(CURDIR)

include $(COMMON_MAKE_PATH)/Makein

all: media_tools

media_tools:
	$(MAKE) -C media_tools

clean:
	$(MAKE) -C media_tools clean