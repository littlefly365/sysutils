TARGET = factor
SRCS = factor.c ../../miscutils/primes/pr_tbl.c
OBJS = $(SRCS:.c=.o)
MAN = factor.1

FLAGS=-DHAVE_OPENSSL -I../../miscutils/primes -Wno-deprecated-declarations

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS) -lcrypto -lcrypt
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CPPFLAGS) $(FLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
