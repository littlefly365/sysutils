#ifndef _COMPAT_UNISTD_H
#define _COMPAT_UNISTD_H

#include_next <unistd.h>
#include <sys/types.h>
#include <grp.h>

void *setmode(const char *p);
mode_t getmode(const void *bbox, mode_t omode);

#endif
