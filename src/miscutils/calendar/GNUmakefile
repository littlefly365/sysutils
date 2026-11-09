TARGET = calendar
SRCS = calendar.c
OBJS = $(SRCS:.c=.o)
MAN = calendar.1

CALENDARS= calendar.birthday calendar.christian calendar.computer calendar.history \
		calendar.holiday calendar.judaic calendar.lotr calendar.music \
		calendar.netbsd calendar.usholiday
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CPPFLAGS)
install:
	install -Dm 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	install -Dm 644 $(MAN) $(DESTDIR)$(PREFIX)/share/man/man1/$(MAN)
	@$(foreach _C_,$(CALENDARS), \
		install -Dm 644 ./calendars/$(_C_) $(DESTDIR)$(PREFIX)/share/calendars/$(_C_)) :
clean:
	rm -rf $(OBJS) $(TARGET)
.PHONY: all install clean
