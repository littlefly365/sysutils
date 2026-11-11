SUBDIR=	base64 basename cat chmod chown chroot cut dirname du \
	echo env factor false hostname link logname mkdir mkfifo \
	mknod mktemp paste printenv pwd realpath rmdir sleep stat \
	sync test true tty uname unlink

all:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) all &&) :
clean:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) clean &&) :
install:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) install &&) :
.PHONY: all clean install
