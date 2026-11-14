#ifndef _COMPAT_SYS_STAT_H
#define _COMPAT_SYS_STAT_H

#include_next <sys/stat.h>

#define st_atimespec	st_atim
#define st_mtimespec	st_mtim
#define st_ctimespec	st_ctim

#endif
