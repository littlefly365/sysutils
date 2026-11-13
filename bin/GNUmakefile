SUBDIR=	cat chmod date domainname echo expr hostname ksh ln mkdir \
	pwd rmdir sleep sync test

all:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) all &&) :
install:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) install &&) :
clean:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) clean &&) :
.PHONY: all install clean
