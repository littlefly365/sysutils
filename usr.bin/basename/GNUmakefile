TARGET = basename
SRCS = basename.c
OBJS = $(SRCS:.c=.o)
MAN = basename.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
	ln -sf $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/dirname.1
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
