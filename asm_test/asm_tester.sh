#!/bin/bash

OUR_PATH=~/corewar/asm_test/our_asm
THEIR_PATH=~/corewar/asm_test/their_asm
CHAMPS_PATH=~/corewar/asm_test/champs

rm $THEIR_PATH/*.cor
rm $OUR_PATH/*.cor

CHAMPS=$CHAMPS_PATH/*.s
for f in $CHAMPS
do
  # echo "Processing $f file..." >/dev/null
  ../asm $f #>/dev/null
  # take action on each file. $f store current file name
done

MOVE=$CHAMPS_PATH/*.cor
for f in $MOVE
do
    mv $f $OUR_PATH
    #printf "\e[32mI move $f in $OUR_PATH\e[0m\n"
done

FILES_THEIR=$THEIR_PATH/*.s
for f in $CHAMPS
do
  # echo "Processing $f file..." >/dev/null
  ../resource/asm $f >/dev/null
  # take action on each file. $f store current file name
done

MOVE=$CHAMPS_PATH/*.cor
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
		if [[ $name1 == $name2 ]]; then
			if ! diff -q $OUR_PATH/$name1 $THEIR_PATH/$name2 &>/dev/null; then
				>&2 printf "\e[31m$name1: KO\e[0m\n"
			else
				>&2 printf "\e[32m$name1: OK\e[0m\n"
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
