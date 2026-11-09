#ifndef _COMPAT_ERR_H
#define _COMPAT_ERR_H

#include_next <err.h>

void errc(int eval, int code, const char *fmt, ...);
void warnc(int code, const char *fmt, ...);

#endif
