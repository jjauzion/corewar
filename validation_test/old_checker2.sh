#!/bin/sh

MYEXE="../corewar"
DEMOEXE="../resource/corewar"
MY_PATH=$0

echo $MY_PATH
#TEST= `$MY_PATH | sed "s%checker.sh%%"`
#echo $TEST

CHAMP1="../test_champ/ldi_test.cor"

for i in {0..1000}
do
	MY_OUTPUT="`$MYEXE -d $i $CHAMP1`"
	DEMO_OUTPUT="`$DEMOEXE -d $i $CHAMP1`"

	if [[ "$MY_OUTPUT" != "$DEMO_OUTPUT" ]]; then
		echo "Diff at iteration $i:"
		$MYEXE -d $i $CHAMP1 > my_output
		$DEMOEXE -d $i $CHAMP1 > demo_output
		echo $MY_OUTPUT
		echo $DEMO_OUTPUT
		diff -u my_output demo_output
		exit
	fi

#	echo "corewar -d $i $CHAMP1" >> demooutput
#	$DEMOEXE -d $i $CHAMP1 >> demooutput

#	echo "corewar -d $i $CHAMP1" >> myoutput
#	$MYEXE -d $i $CHAMP1 >> myoutput
#	echo "corewar -d $i $CHAMP1" >> demooutput
#	$DEMOEXE -d $i $CHAMP1 >> demooutput
done

#diff -u myoutput demooutput
