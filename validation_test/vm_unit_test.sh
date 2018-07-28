#!/bin/sh

MY_EXE="../corewar"
SOURCE_DIR="basic_test"
CHECK_FILE_DIR="check_file"
DIFF_DIR="diff_vm"

DIR="`dirname "${0}"`"
SOURCE_DIR=""$DIR"/"$SOURCE_DIR""
CHECK_FILE_DIR=""$DIR"/"$CHECK_FILE_DIR""
DIFF_DIR=""$DIR"/"$DIFF_DIR""
CHAMPIONSHIP_SRC=""$DIR"/championship"
CHAMPIONSHIP_CHECK_FILE=""$CHECK_FILE_DIR"/championship"
MY_EXE=""$DIR"/"$MY_EXE""

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
	test_file="$SOURCE_DIR/`basename $file | cut -f2- -d'_'`.cor";
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

