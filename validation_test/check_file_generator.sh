#!/bin/bash

TEST_RESULT_DIR="test_result"

ASM_EXE="resource/asm"
EXE="resource/corewar"
COR_DIR="$TEST_RESULT_DIR/their_asm"
OUTPUT_DIR="$TEST_RESULT_DIR/check_file"
CHAMPIONSHIP="championship"
BASIC_TEST="basic_test"

DIR="`dirname "${0}"`"
ASM_EXE=""$DIR"/"$ASM_EXE""
EXE=""$DIR"/"$EXE""
COR_DIR=""$DIR"/"$COR_DIR""
OUTPUT_DIR=""$DIR"/"$OUTPUT_DIR""
CHAMPIONSHIP=""$DIR"/"$CHAMPIONSHIP""
BASIC_TEST=""$DIR"/"$BASIC_TEST""

if ! [ -d $TEST_RESULT_DIR ]; then
	mkdir $TEST_RESULT_DIR
fi
if ! [ -d $COR_DIR ]; then
	mkdir $COR_DIR
	echo -n "Compiling champions ..."
	for champs in "${BASIC_TEST}"/*.s; do
		$ASM_EXE $champs >/dev/null
		cor_file="`echo $champs | rev | cut -d'.' -f2- | rev`.cor"
		mv $cor_file $COR_DIR &>/dev/null
	done
	echo " done !"
fi
if ! [ -d $OUTPUT_DIR ]; then
	mkdir $OUTPUT_DIR
	mkdir "$OUTPUT_DIR/championship"
fi

if [ "${1}" == "basic" ]; then
	BASIC=1
else
	BASIC=0
fi

OPT="-v 31 "
for file in "${COR_DIR}"/*.cor;
do
	output="$OUTPUT_DIR/demo_`basename $file | rev | cut -d'.' -f2- | rev`"; 
	printf "${file} ..."
	$EXE $OPT $file &> $output
	printf "done!\n"
done

if [ $BASIC == 1 ]; then
	exit
fi

OPT="-d "
for file in "$CHAMPIONSHIP"/*.cor;
do
	output="$OUTPUT_DIR/championship/demo_`basename $file | rev | cut -d'.' -f2- | rev`"; 
	rm "$output" 2>/dev/null
	printf "${output} ..."
	for i in 15000 20000 25000 30000;
	do
		$EXE $OPT $i "$file" >> $output 2>&1
	done
	printf "done!\n"
done
