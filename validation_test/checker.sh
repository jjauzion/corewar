#!/bin/sh

MYEXE="../corewar"
DEMOEXE="../resource/corewar"
MY_PATH=$0

echo $MY_PATH
#TEST= `$MY_PATH | sed "s%checker.sh%%"`
#echo $TEST

rm myoutput demooutput

for i in {0..1000}
do
	echo "corewar -d $i $1" >> myoutput
	$MYEXE -d $i $1 >> myoutput
	echo "corewar -d $i $1" >> demooutput
	$DEMOEXE -d $i $1 >> demooutput
done

diff -u myoutput demooutput
