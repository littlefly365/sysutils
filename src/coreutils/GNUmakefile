SUBDIR=	base64 basename cat dirname du echo factor false hostname \
	link logname mkdir realpath sync test true uname unlink

all:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) all &&) :
clean:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) clean &&) :
install:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) install &&) :
.PHONY: all clean install
