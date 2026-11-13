#!/bin/sh
#
# Inspired on <https://github.com/chimera-linux/chimerautils/blob/master/import-src.sh>
#

set -e

CWD="$(pwd -P)"
TMPDIR="$(mktemp -d --tmpdir=${CWD})"
SRCFILE="src.tgz"

fatal()
{
	cd ${CWD}
	printf >&2 "import-src.sh: ${1}\n"
	rm -rf ${TMPDIR}
	exit 1
}

if [ ! -f ${CWD}/upstream.conf ]; then
	fatal "${CWD}/upstream.conf does not exist"
else
	. ${CWD}/upstream.conf
fi

cd ${TMPDIR}
curl -L --retry 3 --ftp-pasv -o "${SRCFILE}" "$SOURCE" || fatal "cannot download ${SRCFILE}"
printf "${SHA512} ${SRCFILE}\n" | sha512sum --quiet --check - || fatal "sha512 mismatch"
tar -xf ${SRCFILE}

copy()
{
	cmd="$(basename ${1})"
	fp="usr/src/${1}"

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

BIN_COMMANDS="
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
bin/sync
bin/test
"

for i in ${BIN_COMMANDS}; do
	copy "${i}"
done

# remove unused files
rm -rf bin/test/TEST.csh

# clean source tree
cd ${CWD}
rm -rf ${TMPDIR}
