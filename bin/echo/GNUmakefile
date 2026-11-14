TARGET = echo
SRCS = echo.c
OBJS = $(SRCS:.c=.o)
MAN = echo.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
