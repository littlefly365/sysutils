SUBDIR=	base64 basename c11 c17 c89 c99 cal calendar \
	cmp col colcrt colrm column comm csplit cut diff \
	diff3 dir dirname du env false flock fold getopt \
	head id logname machine mkfifo mktemp nproc paste \
	npatch printenv realpath rev sdiff sed split stat \
	sw_vers tee touch tr true tty uname uniq unvis \
	users vdir vis wc whereis who xargs yes

all:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) all &&) :
install:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) install &&) :
clean:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) clean &&) :
.PHONY: all install clean
