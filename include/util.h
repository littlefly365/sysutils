#ifndef _UTIL_H
#define _UTIL_H

#include <time.h>

void *emalloc(size_t );
void *ecalloc(size_t, size_t);
void *erealloc(void *, size_t);
char *estrndup(const char *, size_t);
time_t parsedate(const char *, const time_t *, const int *);

static int __attribute__((unused))
raise_default_signal(int sig)
{
	return 0;
}

#endif
