#!/bin/sh

EXE="../resource/corewar"
TEST_DIR="test_champ"
CHAMPIONSHIP="championship"

DIR="`dirname "${0}"`"
TEST_DIR=""$DIR"/"$TEST_DIR""
EXE=""$DIR"/"$EXE""

OPT="-v 31 "
for file in "$TEST_DIR"/*.cor;
do
	output="`dirname $file`/demo_`basename $file | cut -f1 -d'.'`";
	$EXE $OPT $file > $output
done

OPT="-d "
for file in "$CHAMPIONSHIP"/*.cor;
do
	output="`dirname "$file"`/demo_`basename "$file" | cut -f1 -d'.'`";
	rm "$output" 2>/dev/null
	for i in 15000 20000 25000 30000;
	do
		$EXE $OPT $i "$file" >> $output
	done
	echo $output "done"
done
