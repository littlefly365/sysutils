#include <stdarg.h>
#include <errno.h>
#include <err.h>

void
errc(int eval, int code, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	errno = code;
	verr(eval, fmt, ap);
	va_end(ap);
}
