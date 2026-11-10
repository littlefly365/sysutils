#ifndef _COMPAT_STRING_H
#define _COMPAT_STRING_H

#include_next <string.h>
#include <sys/types.h>

void strmode(mode_t, char *);

#endif
