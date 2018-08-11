#!/bin/bash

TEST_RESULT_DIR="test_result"

OUR_PATH="$TEST_RESULT_DIR/our_asm"
THEIR_PATH="$TEST_RESULT_DIR/their_asm"
BASIC_TEST_PATH="basic_test"
CHAMPIONSHIP_PATH="championship"
OUR_EXE="../asm"
THEIR_EXE="resource/asm"
DIFF_PATH="$TEST_RESULT_DIR/diff_asm"

DIR="`dirname "${0}"`"
TEST_RESULT_DIR=""$DIR"/"$TEST_RESULT_DIR""
OUR_PATH=""$DIR"/"$OUR_PATH""
THEIR_PATH=""$DIR"/"$THEIR_PATH""
BASIC_TEST_PATH=""$DIR"/"$BASIC_TEST_PATH""
CHAMPIONSHIP_PATH=""$DIR"/"$CHAMPIONSHIP_PATH""
DIFF_PATH=""$DIR"/"$DIFF_PATH""
OUR_EXE=""$DIR"/"$OUR_EXE""
THEIR_EXE=""$DIR"/"$THEIR_EXE""

mkdir $TEST_RESULT_DIR 2> /dev/null
mkdir $OUR_PATH 2> /dev/null
mkdir $THEIR_PATH 2> /dev/null
mkdir $DIFF_PATH 2> /dev/null

rm $THEIR_PATH/*.cor 2> /dev/null
rm $OUR_PATH/*.cor 2> /dev/null
rm $DIFF_PATH/* 2> /dev/null

CHAMPS=$BASIC_TEST_PATH/*.s
echo "Compiling .cor files:"
for f in $CHAMPS
do
  $OUR_EXE $f >/dev/null
  champ_cor="`echo $f | rev | cut -d'.' -f2- | rev`.cor"
  mv $champ_cor $OUR_PATH 2>/dev/null
  $THEIR_EXE $f >/dev/null
  mv $champ_cor $THEIR_PATH 2>/dev/null
  echo -n "."
done
echo "\nDone!"

for champ_file in "${BASIC_TEST_PATH}"/*.s; do
	their_champ="$THEIR_PATH/`basename $champ_file | cut -d'.' -f1`.cor"
	our_champ="$OUR_PATH/`basename $champ_file | cut -d'.' -f1`.cor"
	if [ -f "${their_champ}" ] && [ -f "${our_champ}" ]; then
		diff="`diff -q $their_champ $our_champ`"
		if ! [ -z "${diff}" ]; then
			result="$DIFF_PATH/KO_`basename $champ_file | cut -d'.' -f1`"
			echo "-----------------------------" > $result
			echo "$diff" >> $result
			printf "\e[31m%-30s:\t[KO]\e[0m\n" `basename ${champ_file}`
		else
			printf "\e[32m%-30s:\t[OK]\e[0m\n" `basename ${champ_file}`
		fi
	elif [ -f $their_champ ] && ! [ -f $our_champ ]; then
		printf "\e[38;5;226m%-30s:\t[SHOULD COMPILE]\e[0m\n" `basename ${champ_file}`
		result="$DIFF_PATH/SHOULD_COMPILE_`basename $champ_file | cut -d'.' -f1`"
		echo "-----------------------------" > $result
		echo "File : $champ_file" >> $result
		echo "Our asm says:" >> $result
		$OUR_EXE $champ_file >> $result 2>&1
	elif ! [ -f $their_champ ] && [ -f $our_champ ]; then
		printf "\e[38;5;202m%-30s:\t[SHOULD NOT COMPILE]\e[0m\n" `basename ${champ_file}`
		result="$DIFF_PATH/SHOULD_NOT_COMPILE_`basename $champ_file | cut -d'.' -f1`"
		echo "-----------------------------" > $result
		echo "File : $champ_file" >> $result
		echo "Their asm says:" >> $result
		$THEIR_EXE $champ_file >> $result 2>&1
	else
		printf "\e[32m%-30s:\t[OK]\e[0m\n" `basename ${champ_file}`
	fi
done

for champ_file in "${CHAMPIONSHIP_PATH}"/*.s; do
	their_champ="$THEIR_PATH/`basename $champ_file | cut -d'.' -f1`.cor"
	our_champ="$OUR_PATH/`basename $champ_file | cut -d'.' -f1`.cor"
	if [ -f "${their_champ}" ] && [ -f "${our_champ}" ]; then
		diff="`diff -q $their_champ $our_champ`"
		if ! [ -z "${diff}" ]; then
			result="$DIFF_PATH/KO_`basename $champ_file | cut -d'.' -f1`"
			echo "-----------------------------" > $result
			echo "$diff" >> $result
			printf "\e[31m%-30s:\t[KO]\e[0m\n" `basename ${champ_file}`
		else
			printf "\e[32m%-30s:\t[OK]\e[0m\n" `basename ${champ_file}`
		fi
	elif [ -f $their_champ ] && ! [ -f $our_champ ]; then
		printf "\e[38;5;226m%-30s:\t[SHOULD COMPILE]\e[0m\n" `basename ${champ_file}`
		result="$DIFF_PATH/SHOULD_COMPILE_`basename $champ_file | cut -d'.' -f1`"
		echo "-----------------------------" > $result
		echo "File : $champ_file" >> $result
		echo "Our asm says:" >> $result
		$OUR_EXE $champ_file >> $result 2>&1
	elif ! [ -f $their_champ ] && [ -f $our_champ ]; then
		printf "\e[38;5;202m%-30s:\t[SHOULD NOT COMPILE]\e[0m\n" `basename ${champ_file}`
		result="$DIFF_PATH/SHOULD_NOT_COMPILE_`basename $champ_file | cut -d'.' -f1`"
		echo "-----------------------------" > $result
		echo "File : $champ_file" >> $result
		echo "Their asm says:" >> $result
		$THEIR_EXE $champ_file >> $result 2>&1
	else
		printf "\e[32m%-30s:\t[OK]\e[0m\n" `basename ${champ_file}`
	fi
done
