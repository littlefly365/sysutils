SUBDIR=	base64 basename cat chown chroot dirname du echo env \
	factor false hostname link logname mkdir mkfifo mknod \
	printenv pwd realpath rmdir sleep stat sync test true \
	uname unlink

all:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) all &&) :
clean:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) clean &&) :
install:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) install &&) :
.PHONY: all clean install
