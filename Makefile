SUBDIR=libcompat src

export TOPDIR := $(shell pwd)

CPPFLAGS=-I$(CURDIR)/include -Dlint -D_GNU_SOURCE
LDFLAGS=-L$(CURDIR)/libcompat -lcompat
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
.PHONY: all install clean
