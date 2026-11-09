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

#include <sys/cdefs.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include "util.h"

static void __dead usage(void);

int
main(int argc, char *argv[])
{
	enum option opt;
	SystemInfo_t info;

	argc--; argv++;

	if ((argc != 0 && argc != 1) || GetOption(*argv, &opt) != 0)
		usage();

	if (GetSystemInfo(&info) != 0)
		err(EXIT_FAILURE, "GetSystemInfo");

	switch (opt) {
	case PRINT_ALL:
		fprintf(stdout, "ProductName:              %s\n"
				"ProductVersion:           %s\n"
				"ProductVersionExtra:      %s\n"
				"BuildVersion:             %s\n",
		info.ProductName, info.ProductVersion,
		info.ProductVersionExtra, info.BuildVersion);
		break;
	case PRINT_NAME:
		fprintf(stdout, "%s\n", info.ProductName);
		break;
	case PRINT_VERSION:
		fprintf(stdout, "%s\n", info.ProductVersion);
		break;
	case PRINT_VERSION_EXTRA:
		fprintf(stdout, "%s\n", info.ProductVersionExtra);
		break;
	case PRINT_BUILD_VERSION:
		fprintf(stdout, "%s\n", info.BuildVersion);
		break;
	}

	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "Usage: %s [--productName|--productVersion|--productVersionExtra|--buildVersion]\n",
		getprogname());
	exit(EXIT_FAILURE);
}
