#!/bin/sh

## ALL COLORS ##
NO_COLOR="\033[0m"
RED_COLOR="\033[31;1m"
GREEN_COLOR="\033[32;1m"
YELLOW_COLOR="\033[33;1m"
BLUE_COLOR="\033[34;1m"
## END ALL COLORS ##
## COLORS FUNCTIONS ##
Cno_color() { echo -e "$@"; }
Cred() { echo -e "$RED_COLOR$@$NO_COLOR"; }
Cgreen() { echo -e "$GREEN_COLOR$@$NO_COLOR"; }
Cyellow() { echo -en "$YELLOW_COLOR$@$NO_COLOR"; }
Cblue() { echo -e "$BLUE_COLOR$@$NO_COLOR"; }
## END COLORS FUNCTIONS ##

PASSED=0
TEST=30
CP_PATH="../../abstractVM"

verif() {
	Cyellow "Test $1: "
	if [ "$DIFF" != "" ]
	then
		Cred "KO"
		echo "Yours:"
		cat -e output.txt
		echo "Excepted:"
		cat -e output/test$i
	elif [[ "$EXIT" -ne 0 ]]
	then
		Cred "KO"
		Cred "Wrong exit!"
	else
		Cgreen "OK"
		PASSED=$(($PASSED + 1))
	fi
}

CompileProgram()
{
	Cblue "Start compilation"
	make fclean -C ../.. > /dev/null
	make -C ../.. > /dev/null
	if [[ $? != 0 ]]
	then
		Cred "Compilation Failed"
		exit 84
	fi
	cp -rf $CP_PATH .
	Cgreen "Compilation terminated"
}

CompileProgram
for i in `seq 1 $TEST`
do
	timeout 10 ./abstractVM input/test$i > output.txt
	EXIT=$(echo $?)
	DIFF=$(diff output.txt output/test$i)
	verif $i
	rm output.txt
done

rm -rf ./abstractVM
PASSED=$(($PASSED*100/$TEST))
Cyellow "Test passed: "
if [[ $PASSED -eq 100 ]]
then
	Cgreen "$PASSED%"
else
	Cred "$PASSED%"
fi
