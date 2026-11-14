TARGET = id
SRCS = id.c
OBJS = $(SRCS:.c=.o)
MANS = id.1 groups.1 whoami.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	ln -sf $(TARGET) $(DESTDIR)$(PREFIX)/bin/groups
	ln -sf $(TARGET) $(DESTDIR)$(PREFIX)/bin/whoami
	@$(foreach m,$(MANS), \
		install -Dm 644 $(m) $(DESTDIR)$(PREFIX)/share/man/man1/$(m);)
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
