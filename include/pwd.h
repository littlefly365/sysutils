#ifndef _COMPAT_PWD_H
#define _COMPAT_PWD_H

#include_next <pwd.h>

int uid_from_user(const char *user, uid_t *uid);

#endif
