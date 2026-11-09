#ifndef _COMPAT_STDLIB_H
#define _COMPAT_STDLIB_H

#include_next <stdlib.h>

const char *getprogname(void);
void setprogname(const char *);
int reallocarr(void *, size_t, size_t);
long long strtonum(const char *, long long, long long, const char **);

#endif
