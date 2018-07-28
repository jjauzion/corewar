#!/bin/bash

OUR_PATH="our_asm"
THEIR_PATH="their_asm"
BASIC_TEST_PATH="basic_test"
CHAMPIONSHIP_PATH="championship"
OUR_EXE="../asm"
THEIR_EXE="resource/asm"
DIFF_PATH="diff_asm"

DIR="`dirname "${0}"`"
OUR_PATH=""$DIR"/"$OUR_PATH""
THEIR_PATH=""$DIR"/"$THEIR_PATH""
BASIC_TEST_PATH=""$DIR"/"$BASIC_TEST_PATH""
CHAMPIONSHIP_PATH=""$DIR"/"$CHAMPIONSHIP_PATH""
DIFF_PATH=""$DIR"/"$DIFF_PATH""
OUR_EXE=""$DIR"/"$OUR_EXE""
THEIR_EXE=""$DIR"/"$THEIR_EXE""

mkdir $OUR_PATH 2> /dev/null
mkdir $THEIR_PATH 2> /dev/null
mkdir $DIFF_PATH 2> /dev/null

rm $THEIR_PATH/*.cor 2> /dev/null
rm $OUR_PATH/*.cor 2> /dev/null

CHAMPS=$BASIC_TEST_PATH/*.s
for f in $CHAMPS
do
  # echo "Processing $f file..." >/dev/null
  $OUR_EXE $f #>/dev/null
  #output="$BASIC_TEST_PATH/`basename $f | cut -d'.' -f1`.cor"
  # take action on each file. $f store current file name
done

MOVE=$BASIC_TEST_PATH/*.cor
for f in $MOVE
do
    mv $f $OUR_PATH
    #printf "\e[32mI move $f in $OUR_PATH\e[0m\n"
done

for f in $CHAMPS
do
  # echo "Processing $f file..." >/dev/null
  $THEIR_EXE $f >/dev/null
  # take action on each file. $f store current file name
done

MOVE=$BASIC_TEST_PATH/*.cor
for f in $MOVE
do
    mv $f $THEIR_PATH
    #printf "\e[31mI move $f in $OUR_PATH\e[0m\n"
done


OUR_COR=$OUR_PATH/*.cor
THEIR_COR=$THEIR_PATH/*.cor


for f in $OUR_COR
do
	for d in $THEIR_COR
	do
		name1=${f##*/}
		name2=${d##*/}
		# echo "Name1: $name1"
		# echo "Name2: $name2"
		result="$DIFF_PATH/diff_`basename $f`"
		rm $result 2>/dev/null
		if [[ $name1 == $name2 ]]; then
			diff="`diff -q $OUR_PATH/$name1 $THEIR_PATH/$name2`"
			if ! [ -z "${diff}" ]; then
				echo "$diff" > $result
				printf "\e[31m$name1: KO\e[0m\n"
			else
				printf "\e[32m$name1: OK\e[0m\n"
			fi
		fi
	done
done


#Find files that should compile
for f in $OUR_COR
do
    finded=0
    for d in $THEIR_COR
    do
    name1=${f##*/}
    name2=${d##*/}
    if [[ $name1 == $name2 ]]; then
        finded=1
    fi
    done
    if [[ $finded == 0 ]]; then
        printf "\e[38;5;202mKO : $name1 compile but it shouldn't\e[0m\n"
    fi
done

#find files that shoul compile bit does not
for f in $THEIR_COR
do
    finded=0
    for d in $OUR_COR
    do
    name1=${f##*/}
    name2=${d##*/}
    if [[ $name1 == $name2 ]]; then
        finded=1
    fi
    done
    if [[ $finded == 0 ]]; then
        printf "\e[38;5;226mKO : $name1 may compile but doesn't\e[0m\n"
    fi
done

#printf "\e[31mKO : $(diff -r $THEIR_PATH $OUR_PATH)\e[0m\n"
