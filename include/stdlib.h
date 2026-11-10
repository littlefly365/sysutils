#ifndef _COMPAT_STDLIB_H
#define _COMPAT_STDLIB_H

#include_next <stdlib.h>

const char *getprogname(void);
void setprogname(const char *);
int reallocarr(void *, size_t, size_t);
long long strtonum(const char *, long long, long long, const char **);
int humanize_number(char *, size_t, int64_t, const char *, int, int);
char *getbsize(int *, long *);

#define	HN_DECIMAL		0x01
#define	HN_NOSPACE		0x02
#define	HN_B			0x04
#define	HN_DIVISOR_1000		0x08

#define	HN_GETSCALE		0x10
#define	HN_AUTOSCALE		0x20

#endif
