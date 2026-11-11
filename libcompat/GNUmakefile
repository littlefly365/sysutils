LIB=libcompat.a
SRCS=	efun.c errc.c fgetln.c fparseln.c getbsize.c humanize_number.c \
	progname.c pwcache.c reallocarr.c setmode.c strmode.c strtonum.c \
	unvis.c vis.c
OBJS=$(SRCS:.c=.o)

all: $(OBJS)
	ar rcs $(LIB) $(OBJS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) -D'_DIAGASSERT(x)='
install:

clean:
	rm -rf $(OBJS) $(LIB)
.PHONY: all install clean
