TARGET = sdiff
SRCS = common.c edit.c sdiff.c
OBJS = $(SRCS:.c=.o)
MAN = sdiff.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS) -lm
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS) -D'SIZE_T_MAX=SIZE_MAX'
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
