#!/bin/sh

MY_EXE="../corewar"
TEST_DIR="test_champ"
CHAMPIONSHIP="championship"

DIR="`dirname "${0}"`"
TEST_DIR=""$DIR"/"$TEST_DIR""
CHAMPIONSHIP=""$DIR"/"$CHAMPIONSHIP""
MY_EXE=""$DIR"/"$MY_EXE""

RED="\033[0;31m"
GREEN="\033[0;32m"
NC="\033[0m"

if [ "${1}" == "basic" ]; then
	BASIC=1
else
	BASIC=0
fi
OPT="-klcpo"
for file in "${TEST_DIR}"/demo_*;
do
	test_file="`dirname $file`/`basename $file | cut -f2- -d'_'`.cor";
	output="`dirname $test_file`/vm_`basename $test_file | cut -f1 -d'.'`"
	diff="`dirname $test_file`/diff_`basename $test_file | cut -f1 -d'.'`"
	$MY_EXE $OPT $test_file > $output
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
for file in "${CHAMPIONSHIP}"/demo_*;
do
	test_file="`dirname $file`/`basename $file | cut -f2- -d'_'`.cor";
	output="`dirname $test_file`/vm_`basename $test_file | cut -f1 -d'.'`"
	diff="`dirname $test_file`/diff_`basename $test_file | cut -f1 -d'.'`"
	rm $output 2>/dev/null
	rm $diff 2>/dev/null
	for i in 15000 20000 25000 30000;
	do
		$MY_EXE $OPT $i $test_file >> $output
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

