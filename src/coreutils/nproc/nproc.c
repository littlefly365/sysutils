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
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <err.h>

enum {
	ALL_OPT = 1000,
	IGNORE_OPT
};

static const struct option longopts[] = {
	{ "all", no_argument, 0, ALL_OPT },
	{ "ignore", required_argument, 0, IGNORE_OPT },
	{ 0, 0, 0, 0}
};

static void __dead usage(void);

int
main(int argc, char *argv[])
{
	int c, nproc;
	const char *errstr;
	int conf, all, ignore;

	conf = ignore = all = 0;

	while ((c = getopt_long(argc, argv, "", longopts, NULL)) != -1) {
		switch (c) {
		case ALL_OPT:
			conf = _SC_NPROCESSORS_CONF;
			break;
		case IGNORE_OPT:
			ignore = strtonum(optarg, 0, INT_MAX, &errstr);
			if (errstr || *optarg == '\0')
				errx(1, "invalid number: '%s'", optarg);
			break;
		default:
			usage();
			break;
		}
	}

	if (argc != optind)
		usage();

	if (conf == 0)
		conf = _SC_NPROCESSORS_CONF;

	if ((nproc = sysconf(conf)) == -1)
		err(1, "sysconf");

	nproc -= ignore;

	if (nproc <= 0)
		nproc = 1;
	
	printf("%d\n", nproc);
	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s [--all] [--ignore=N]\n", getprogname());
	exit(1);
}
