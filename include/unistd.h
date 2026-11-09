#ifndef _COMPAT_UNISTD_H
#define _COMPAT_UNISTD_H

#include <sys/types.h>
#include_next <unistd.h>

void *setmode(const char *p);
mode_t getmode(const void *bbox, mode_t omode);

#endif
