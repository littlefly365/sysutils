TARGET = machine
SCRIPT = machine.sh
MAN = machine.1

all:

install:
	install -Dm 755 $(SCRIPT) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
	ln -sf $(TARGET) $(DESTDIR)$(PREFIX)/bin/arch
clean:

.PHONY: all install clean
