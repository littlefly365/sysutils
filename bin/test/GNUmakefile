TARGET = test
SRCS = test.c
OBJS = $(SRCS:.c=.o)
MAN = test.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS) -include time.h
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
	ln -sf $(TARGET) $(DESTDIR)$(PREFIX)/bin/[
	ln -sf $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/[.1
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
