TARGET = c89
SCRIPT = c89.sh
MAN = c89.1

all:

install:
	install -Dm 755 $(SCRIPT) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
clean:

.PHONY: all install clean
