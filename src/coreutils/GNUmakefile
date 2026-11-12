SUBDIR=	base64 basename cat chmod chown chroot comm csplit cut \
	dir dirname du echo env expr factor false hostname link \
	logname mkdir mkfifo mknod mktemp paste printenv pwd \
	realpath rmdir sleep split stat sync test tr true tty \
	uname unlink users vdir wc who yes

all:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) all &&) :
clean:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) clean &&) :
install:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) install &&) :
.PHONY: all clean install
