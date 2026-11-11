// from src/lib/libutil/efun.c (NetBSD)

#include <stdlib.h>
#include <util.h>
#include <err.h>

static void (*efunc)(int, const char *, ...) = err;

void *
emalloc(size_t n)
{
	void *p = malloc(n);
	if (p == NULL && n != 0)
		(*efunc)(1, "Cannot allocate %zu bytes", n);
	return p;
}

void *
ecalloc(size_t n, size_t s)
{
	void *p = calloc(n, s);
	if (p == NULL && n != 0 && s != 0)
		(*efunc)(1, "Cannot allocate %zu blocks of size %zu", n, s);
	return p;
}

void *
erealloc(void *p, size_t n)
{
	void *q = realloc(p, n);
	if (q == NULL && n != 0)
		(*efunc)(1, "Cannot re-allocate %zu bytes", n);
	return q;
}
