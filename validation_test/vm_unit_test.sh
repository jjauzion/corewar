#!/bin/bash

TEST_RESULT_DIR="test_result"

OUR_COR="$TEST_RESULT_DIR/our_asm"
THEIR_COR="$TEST_RESULT_DIR/their_asm"
CHECK_FILE_DIR="$TEST_RESULT_DIR/check_file"
DIFF_DIR="$TEST_RESULT_DIR/diff_vm"
MY_EXE="../corewar"
THEIR_ASM="resource/asm"
OUR_ASM="../asm"

DIR="`dirname "${0}"`"
TEST_RESULT_DIR=""$DIR"/"$TEST_RESULT_DIR""
OUR_COR=""$DIR"/"$OUR_COR""
THEIR_COR=""$DIR"/"$THEIR_COR""
CHECK_FILE_DIR=""$DIR"/"$CHECK_FILE_DIR""
DIFF_DIR=""$DIR"/"$DIFF_DIR""
MY_EXE=""$DIR"/"$MY_EXE""
THEIR_ASM=""$DIR"/"$THEIR_ASM""
OUR_ASM=""$DIR"/"$OUR_ASM""

CHAMPIONSHIP_SRC=""$DIR"/championship"
CHAMPIONSHIP_CHECK_FILE=""$CHECK_FILE_DIR"/championship"
BASIC_TEST=""$DIR"/basic_test"

if ! [ -f $OUR_ASM ]; then
	echo "Using their asm"
	ASM_EXE=$THEIR_ASM
	COR_DIR=$THEIR_COR
else
	echo "Using our asm"
	ASM_EXE=$OUR_ASM
	COR_DIR=$OUR_COR
fi

if ! [ -d $TEST_RESULT_DIR ]; then
	mkdir $TEST_RESULT_DIR
fi
if ! [ -d $COR_DIR ]; then
	mkdir $COR_DIR
fi
if ! [ -d $DIFF_DIR ]; then
	mkdir $DIFF_DIR
fi

RED="\033[0;31m"
GREEN="\033[0;32m"
NC="\033[0m"

if [ "${1}" == "basic" ]; then
	BASIC=1
else
	BASIC=0
fi
OPT="-klcpo"
for file in "${CHECK_FILE_DIR}"/demo_*;
do
	test_file="$COR_DIR/`basename $file | cut -f2- -d'_'`.cor";
	if ! [ -f $test_file ]; then
		s_file="$BASIC_TEST/`basename $test_file | rev | cut -d'.' -f2- | rev`.s"
		$ASM_EXE $s_file &>/dev/null
		cor_file="`echo $s_file | rev | cut -d'.' -f2- | rev`.cor"
		mv $cor_file $COR_DIR
	fi
	output="$CHECK_FILE_DIR/vm_`basename $test_file | cut -f1 -d'.'`"
	diff="$DIFF_DIR/diff_`basename $test_file | cut -f1 -d'.'`"
	$MY_EXE $OPT $test_file &> $output
	rm $diff 2>/dev/null
	result="`diff -u $file $output`"
	if ! [ -z "${result}" ]; then
		echo "$result" > $diff
		printf "%-30s\t${RED}[KO]${NC}\n" `basename ${test_file}`
		printf "\t--> See diff file : ${diff}\n"
	else
		printf "%-30s\t${GREEN}[OK]${NC}\n" `basename ${test_file}`
	fi
done

if [ $BASIC == 1 ]; then
	exit
fi

OPT="-d "
for file in "${CHAMPIONSHIP_CHECK_FILE}"/demo_*;
do
	test_file="$CHAMPIONSHIP_SRC/`basename $file | cut -f2- -d'_'`.cor";
	output="$CHAMPIONSHIP_CHECK_FILE/vm_`basename $test_file | cut -f1 -d'.'`"
	diff="$DIFF_DIR/diff_`basename $test_file | cut -f1 -d'.'`"
	rm $output 2>/dev/null
	rm $diff 2>/dev/null
	for i in 15000 20000 25000 30000;
	do
		$MY_EXE $OPT $i $test_file >> $output 2>&1
	done
	result="`diff -u $file $output`"
	if ! [ -z "${result}" ]; then
		echo "$result" > $diff
		printf "%-30s\t${RED}[KO]${NC}\n" `basename ${test_file}`
		printf "\t--> See diff file : ${diff}\n"
	else
		printf "%-30s\t${GREEN}[OK]${NC}\n" `basename ${test_file}`
	fi
done

