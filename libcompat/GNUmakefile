LIB=libcompat.a
SRCS=errc.c fgetln.c fparseln.c progname.c reallocarr.c setmode.c strtonum.c unvis.c vis.c
OBJS=$(SRCS:.c=.o)

all: $(OBJS)
	ar rcs $(LIB) $(OBJS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) -D'_DIAGASSERT(x)='
install:

clean:
	rm -rf $(OBJS) $(LIB)
.PHONY: all install clean
