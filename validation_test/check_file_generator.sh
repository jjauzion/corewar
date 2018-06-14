#!/bin/sh

EXE="../resource/corewar"
TEST_DIR="test_champ"

DIR="`dirname "${0}"`"
TEST_DIR=""$DIR"/"$TEST_DIR""
EXE=""$DIR"/"$EXE""

if [ -z "${1}" ]; then
	OPT="-v 23"
else
	OPT=$1
fi

if ! [ -z "${2}" ]; then
	output="`dirname $2`/demo_`basename $2 | cut -f1 -d'.'`";
	$EXE $OPT $2 > $output
	exit
fi

for file in "$TEST_DIR"/*.cor;
do
	output="`dirname $file`/demo_`basename $file | cut -f1 -d'.'`";
	$EXE $OPT $file > $output
done
