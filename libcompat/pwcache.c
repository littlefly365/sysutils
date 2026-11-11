#include <pwd.h>

int
uid_from_user(const char *user, uid_t *uid)
{
	struct passwd *pw = getpwnam(user);
	if (!pw)
		return -1;
	*uid = pw->pw_uid;
	return 0;
}
