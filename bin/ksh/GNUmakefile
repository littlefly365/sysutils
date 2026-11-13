TARGET = ksh
SRCS = alloc.c c_ksh.c c_sh.c c_test.c c_ulimit.c edit.c emacs.c \
	eval.c exec.c expr.c history.c io.c jobs.c lex.c mail.c \
	main.c misc.c path.c shf.c syn.c table.c trap.c tree.c tty.c \
	var.c version.c vi.c
OBJS = $(SRCS:.c=.o)
MAN = ksh.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CPPFLAGS) \
		-Wno-old-style-definition -include time.h
install: $(MAN)
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
	ln -sf $(TARGET) $(DESTDIR)$(PREFIX)/bin/sh
	ln -sf $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/sh.1
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
