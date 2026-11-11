TARGET = stat
SRCS = stat.c
OBJS = $(SRCS:.c=.o)
MANS = stat.1 readlink.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CPPFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	ln -sf $(TARGET) $(DESTDIR)$(PREFIX)/bin/readlink
	@$(foreach m,$(MANS), \
		install -Dm 644 $(m) $(DESTDIR)$(PREFIX)/share/man/man1/$(m);)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
