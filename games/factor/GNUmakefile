TARGET = factor
SRCS = factor.c ../primes/pr_tbl.c
OBJS = $(SRCS:.c=.o)
MAN = factor.6

FLAGS=-DHAVE_OPENSSL -I../primes -Wno-deprecated-declarations

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS) -lcrypto -lcrypt
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS) $(FLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man6/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
