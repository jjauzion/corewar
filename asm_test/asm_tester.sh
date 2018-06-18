#!/bin/bash

OUR_PATH=~/Documents/corewar/asm_test/our_asm
THEIR_PATH=~/Documents/corewar/asm_test/their_asm

FILES_OUR=$OUR_PATH/*.s
for f in $FILES_OUR
do
  # echo "Processing $f file..." >/dev/null
  ../asm $f >/dev/null
  # take action on each file. $f store current file name
done

FILES_THEIR=$THEIR_PATH/*.s
for f in $FILES_THEIR
do
  # echo "Processing $f file..." >/dev/null
  ../resource/asm $f >/dev/null
  # take action on each file. $f store current file name
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
