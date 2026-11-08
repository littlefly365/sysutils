#ifndef _COMPAT_STDLIB_H
#define _COMPAT_STDLIB_H

#include_next <stdlib.h>

extern const char *__progname;

static const char *
getprogname(void)
{
	return __progname;
}

static void
setprogname(const char *progname)
{
}

#endif
