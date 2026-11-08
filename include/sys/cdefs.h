#ifndef _COMPAT_SYS_CDEFS_H
#define _COMPAT_SYS_CDEFS_H

#include <features.h>

#if defined(__GLIBC__)
#include_next <sys/cdefs.h>
#endif

#ifndef __arraycount
#define __arraycount(a)	(sizeof(a) / sizeof(*(a)))
#endif

#define __dead

#define __COPYRIGHT(x)
#define __RCSID(x)

#endif
