#ifndef _COMPAT_SIGNAL_H
#define _COMPAT_SIGNAL_H

#include_next <signal.h>

int signalnumber(const char *);
int signalnext(int);
const char *signalname(int);

#endif
