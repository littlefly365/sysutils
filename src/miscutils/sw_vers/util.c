/*
 *  Copyright (c) 2026, littlefly365
 * 
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 * 
 *  1. Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <sys/utsname.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "util.h"

/* you should overwrite this for your build */
#ifndef _BUILDID
#define _BUILDID	"26A100"
#endif

int
GetSystemInfo(SystemInfo_t *info)
{
#ifdef __linux__
	FILE *fp;
	size_t len = 0;
	char *line = NULL;
#endif
	struct utsname uts;
	if (uname(&uts) != 0)
		return -1;

	strlcpy(info->ProductVersionExtra, "(a)", INFOSIZE);
	strlcpy(info->BuildVersion, _BUILDID, INFOSIZE);

#ifdef __linux__
	char distro[INFOSIZE];
	char version[INFOSIZE];

	const char *filename = "/etc/os-release";
	if (access(filename, R_OK) != 0)
		filename = "/usr/lib/os-release";

	if ((fp = fopen(filename, "r")) != NULL) {
		while (getline(&line, &len, fp) != -1) {
			if (!strncmp(line, "NAME=", 5))
				strlcpy(distro, line + 5, INFOSIZE);
			if (!strncmp(line, "VERSION=", 8))
				strlcpy(version, line + 8, INFOSIZE);
		}

		distro[strcspn(distro, "\n")] = '\0';
		version[strcspn(version, "\n")] = '\0';

		char *d = distro;
		if (*d == '"') {
			d++;
			char *p = strrchr(d, '"');
			if (p != NULL)
				*p = '\0';
		}

		char *v = version;
		if (*v == '"') {
			v++;
			char *p = strrchr(v, '"');
			if (p != NULL)
				*p = '\0';
		}

		strlcpy(info->ProductName, d, INFOSIZE);
		if (version[0] == '\0')
			strlcpy(info->ProductVersion, uts.release, INFOSIZE);
		else
			strlcpy(info->ProductVersion, v, INFOSIZE);

		if (line)
			free(line);

		return 0;
	}

#endif
	strlcpy(info->ProductName, uts.sysname, INFOSIZE);
	strlcpy(info->ProductVersion, uts.release, INFOSIZE);
	return 0;
}

int
GetOption(char *arg, enum option *opt)
{
	*opt = UNKNOWN_OPT;

	if (arg == NULL)
		*opt = PRINT_ALL;
	else if (!strcmp(arg, "-productName") || !strcmp(arg, "--productName"))
		*opt = PRINT_NAME;
	else if (!strcmp(arg, "-productVersion") || !strcmp(arg, "--productVersion"))
		*opt = PRINT_VERSION;
	else if (!strcmp(arg, "--productVersionExtra"))
		*opt = PRINT_VERSION_EXTRA;
	else if (!strcmp(arg, "-buildVersion") || !strcmp(arg, "--buildVersion"))
		*opt = PRINT_BUILD_VERSION;

	return (*opt == UNKNOWN_OPT);
}
