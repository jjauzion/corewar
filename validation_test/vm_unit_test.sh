#!/bin/sh

MY_EXE="../corewar"

#MY_PATH=$0
#TEST= `$MY_PATH | sed "s%checker.sh%%"`
#echo $TEST

if [ -z "${2}" ]; then
	OPT="-lcpo"
else
	OPT=$2
fi

if ! [ -z "${1}" ]; then
	demo="`dirname $1`/demo_`basename $1 | cut -f1 -d'.'`"
	output="`dirname $1`/vm_`basename $1 | cut -f1 -d'.'`"
	diff="`dirname $1`/diff_`basename $1 | cut -f1 -d'.'`"
	$MY_EXE $OPT $1 > $output
	rm $diff 2>/dev/null
	result="`diff -u $demo $output`"
	if ! [ -z "${result}" ]; then
		echo "$result" > $diff
	fi
	exit
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
