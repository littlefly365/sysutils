TARGET = nologin
SCRIPT = nologin.sh
MAN = nologin.8

all:

install:
	install -Dm 755 $(SCRIPT) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man8/$(MAN)
clean:

.PHONY: all install clean
