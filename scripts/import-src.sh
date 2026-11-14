#!/bin/sh
#
# Inspired on <https://github.com/chimera-linux/chimerautils/blob/master/import-src.sh>
#

#
# Note 1: dir, vdir, sw_vers and nproc are not in the lists, because
# they don't come from NetBSD. (they were made from scratch)
#

set -e

CWD="$(pwd -P)"
TMPDIR="$(mktemp -d --tmpdir=${CWD})"
SRCFILES="bin.tar.gz sbin.tar.gz usr.bin.tar.gz usr.sbin.tar.gz games.tar.gz"

fatal()
{
	cd ${CWD}
	printf >&2 "import-src.sh: ${1}\n"
	rm -rf ${TMPDIR}
	exit 1
}

if [ ! -f ${CWD}/etc/upstream.conf ]; then
	fatal "${CWD}/etc/upstream.conf does not exist"
else
	. ${CWD}/etc/upstream.conf
fi

cd ${TMPDIR}
for i in ${SRCFILES}; do
	curl -L --retry 3 --ftp-pasv -o "${i}" "${URL}/${i}" || fatal "cannot download ${i}"
done

sha512sum -c ${CWD}/etc/sha512sum.txt || fatal "sha512 mismatch"

for i in ${SRCFILES}; do
	tar -xf ${i}
done

copy()
{
	cmd="$(basename ${1})"
	fp="src/${1}"

	# we don't want the Makefiles
	rm -rf "${fp}/Makefile"

	# remove the CVS directory
	rm -rf "${fp}/CVS"

	# if exists remove the tests directory
	[ -d "${fp}/tests" ] && rm -rf "${fp}/tests"

	# copy the directory content to our source tree
	cp -r ${fp}/* "${CWD}/${1}/"

	# apply patch if needed
	if [ -f "${CWD}/${1}/${cmd}.diff" ]; then
		cd "${CWD}/${1}"
		patch -d "${CWD}/${1}" -p1 < "${CWD}/${1}/${cmd}.diff"
		cd "${TMPDIR}"
	fi
}

BIN_CMDS="
bin/cat
bin/chmod
bin/date
bin/domainname
bin/echo
bin/expr
bin/hostname
bin/ksh
bin/ln
bin/mkdir
bin/pwd
bin/rmdir
bin/sleep
bin/stty
bin/sync
bin/test
"

SBIN_CMDS="
sbin/chown
sbin/mknod
sbin/nologin
"

USR_BIN_CMDS="
usr.bin/base64
usr.bin/basename
usr.bin/c11
usr.bin/c17
usr.bin/c89
usr.bin/c99
usr.bin/cal
usr.bin/calendar
usr.bin/cmp
usr.bin/col
usr.bin/colcrt
usr.bin/colrm
usr.bin/column
usr.bin/comm
usr.bin/csplit
usr.bin/cut
usr.bin/dirname
usr.bin/du
usr.bin/env
usr.bin/false
usr.bin/flock
usr.bin/fold
usr.bin/getopt
usr.bin/head
usr.bin/id
usr.bin/logname
usr.bin/machine
usr.bin/mkfifo
usr.bin/mktemp
usr.bin/paste
usr.bin/patch
usr.bin/printenv
usr.bin/realpath
usr.bin/rev
usr.bin/sdiff
usr.bin/sed
usr.bin/split
usr.bin/stat
usr.bin/tee
usr.bin/touch
usr.bin/tr
usr.bin/true
usr.bin/tty
usr.bin/uname
usr.bin/uniq
usr.bin/unvis
usr.bin/users
usr.bin/vis
usr.bin/wc
usr.bin/whereis
usr.bin/who
usr.bin/xargs
usr.bin/yes
"

USR_SBIN_CMDS="
usr.sbin/chroot
usr.sbin/link
usr.sbin/unlink
"

GAMES_CMDS="
games/banner
games/factor
games/primes
"

for i in ${BIN_CMDS} ${SBIN_CMDS} ${USR_BIN_CMDS} ${USR_SBIN_CMDS} ${GAMES_CMDS}; do
	copy "${i}"
done

cd ${CWD}

# remove unused files/directories
rm -rf bin/test/TEST.csh
rm -rf usr.bin/calendar/calendars/CVS/

# clean source tree
rm -rf ${TMPDIR}
