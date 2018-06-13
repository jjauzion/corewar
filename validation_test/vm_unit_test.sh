#!/bin/sh

MY_EXE="../corewar"
DEMO_EXE="../resource/corewar"

#MY_PATH=$0
#TEST= `$MY_PATH | sed "s%checker.sh%%"`
#echo $TEST

if [ -z "${1}" ]; then
	OPT="-lcpo"
else
	OPT=$1
fi

for file in test_champ/demo_*;
do
	test_file="`dirname $file`/`basename $file | cut -f2- -d'_'`.cor";
	output="`dirname $test_file`/vm_`basename $test_file | cut -f1 -d'.'`"
	diff="`dirname $test_file`/diff_`basename $test_file | cut -f1 -d'.'`"
	$MY_EXE $OPT $test_file > $output
	rm $diff 2>/dev/null
	result="`diff -u $file $output`"
	if ! [ -z "${result}" ]; then
		echo "$result" > $diff
	fi
done
