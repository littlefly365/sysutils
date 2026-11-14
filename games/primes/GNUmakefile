TARGET = primes
SRCS = pattern.c primes.c pr_tbl.c spsp.c
OBJS = $(SRCS:.c=.o)
MAN = primes.6

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS) -lm
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man6/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
