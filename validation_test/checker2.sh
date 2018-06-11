#!/bin/sh

MYEXE="../corewar"
DEMOEXE="../resource/corewar"

MY_PATH=$0
#TEST= `$MY_PATH | sed "s%checker.sh%%"`
#echo $TEST

TMP="-final"

if [[ "$2" == "$TMP" ]]; then
	$MYEXE -d $3 $1 > myoutput
	$DEMOEXE -d $3 $1 > demooutput
	diff -u myoutput demooutput
	exit
fi

rm myoutput demooutput

for i in {0..500}
do
	echo "cycle $i"
	echo "corewar -d $i $1" > myoutput
	$MYEXE -d $i $1 > myoutput
	echo "corewar -d $i $1" > demooutput
	$DEMOEXE -d $i $1 > demooutput
	diff -u myoutput demooutput > diff_file
	if [[ "`cat diff_file`" ]]; then
		echo "Diff at cycle $i:\n"
		cat diff_file
		exit
	fi
done

