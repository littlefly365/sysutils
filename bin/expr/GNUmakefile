TARGET = expr
YSRCS = expr.y
SRCS = expr.c
OBJS = $(SRCS:.c=.o)
MAN = expr.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
$(SRCS): $(YSRCS)
	byacc -o $@ $<
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
clean:
	rm -rf $(SRCS) $(OBJS) $(TARGET)
.PHONY: all install clean
