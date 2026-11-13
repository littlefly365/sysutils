TARGET = sync
SRCS = sync.c
OBJS = $(SRCS:.c=.o)
MAN = sync.8

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CPPFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man8/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
