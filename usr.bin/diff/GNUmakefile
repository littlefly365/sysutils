TARGET = diff
SRCS = diff.c diffdir.c diffreg.c pr.c xmalloc.c
OBJS = $(SRCS:.c=.o)
MAN = diff.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS) -lm
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
