SUBDIR=lib bin sbin usr.bin usr.sbin games

CPPFLAGS=-I$(CURDIR)/include -Dlint -D_GNU_SOURCE
LDFLAGS=-L$(CURDIR)/lib/libcompat -lcompat
CFLAGS=

DESTDIR ?=
PREFIX ?= /usr/local

export CPPFLAGS LDFLAGS CFLAGS DESTDIR PREFIX

all:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) all &&) :
install:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) install &&) :
clean:
	@$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) clean &&) :
import:
	@./scripts/import-src.sh
.PHONY: all install clean
