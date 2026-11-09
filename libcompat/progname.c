#include <stdlib.h>

extern const char *__progname;

const char *
getprogname(void)
{
        return __progname;
}

void
setprogname(const char *progname)
{
}
