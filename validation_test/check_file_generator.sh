#!/bin/sh

EXE="../resource/corewar"
TEST_DIR="test_champ"
CHAMPIONSHIP="championship"

DIR="`dirname "${0}"`"
TEST_DIR=""$DIR"/"$TEST_DIR""
EXE=""$DIR"/"$EXE""

if [ "${1}" == "basic" ]; then
	BASIC=1
else
	BASIC=0
fi

OPT="-v 31 "
for file in "$TEST_DIR"/*.cor;
do
	output="`dirname $file`/demo_`basename $file | rev | cut -d'.' -f2- | rev`"; 
	printf "${file} ..."
	$EXE $OPT $file > $output
	printf "done!\n"
done

if [ $BASIC == 1 ]; then
	exit
fi

OPT="-d "
for file in "$CHAMPIONSHIP"/*.cor;
do
	output="`dirname $file`/demo_`basename $file | rev | cut -d'.' -f2- | rev`"; 
	rm "$output" 2>/dev/null
	printf "${output} ..."
	for i in 15000 20000 25000 30000;
	do
		$EXE $OPT $i "$file" >> $output
	done
	printf "done!\n"
done
