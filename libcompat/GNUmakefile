LIB=libcompat.a
SRCS=vis.c unvis.c
OBJS=$(SRCS:.c=.o)

all: $(OBJS)
	ar rcs $(LIB) $(OBJS)
%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) -D'_DIAGASSERT(x)='
install:

clean:
	rm -rf $(OBJS) $(LIB)
.PHONY: all install clean
