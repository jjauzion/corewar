#!/bin/sh

EXE="resource/corewar"
TEST_DIR="basic_test"
OUTPUT_DIR="check_file"
CHAMPIONSHIP="championship"

DIR="`dirname "${0}"`"
EXE=""$DIR"/"$EXE""
TEST_DIR=""$DIR"/"$TEST_DIR""
OUTPUT_DIR=""$DIR"/"$OUTPUT_DIR""
CHAMPIONSHIP=""$DIR"/"$CHAMPIONSHIP""

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
for file in "$TEST_DIR"/*.cor;
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
