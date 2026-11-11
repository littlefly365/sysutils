SUBDIR=	banner c11 c17 c89 c99 cal calendar col domainname flock \
	getopt machine primes rev sw_vers unvis vis whereis

all:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) all &&) :
clean:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) clean &&) :
install:
	@$(foreach dir,$(SUBDIR),$(MAKE) -C $(dir) install &&) :
.PHONY: all clean install
