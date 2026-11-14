TARGET = chroot
SRCS = chroot.c
OBJS = $(SRCS:.c=.o)
MAN = chroot.8

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/sbin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man8/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
