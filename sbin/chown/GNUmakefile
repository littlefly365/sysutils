TARGET = chown
SRCS = chown.c
OBJS = $(SRCS:.c=.o)
MANS = chown.8 chgrp.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CPPFLAGS) -DSUPPORT_DOT
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	ln -sf $(TARGET) $(DESTDIR)$(PREFIX)/bin/chgrp
	install -Dm 644 chown.8 $(DESTDIR)$(PREFIX)/share/man/man8/chown.8
	install -Dm 644 chgrp.1 $(DESTDIR)$(PREFIX)/share/man/man1/chgrp.1
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
