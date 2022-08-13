#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Usage: tester.sh  number_count"
	exit
fi

if [ `command -v ruby` ]; then
	ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
else
	ARG=`python - "$1" << [HEREDOC]
import sys
import random

if len(sys.argv) != 2:
        print("argument error")
        sys.exit()

try:
        max = int(sys.argv[1])
except:
        print("Not number")
        sys.exit()

list = range(1, max + 1)
random.shuffle(list)
print ' '.join(str(s) for s in list)
[HEREDOC]`
fi

PUSH_SWAP=./push_swap
CHECKER=./checker

if [ ! `command -v $PUSH_SWAP` ]; then
	echo "$PUSH_SWAP not found"
	exit
fi

if [ "$2" = "" ]; then
	if [ ! `command -v $CHECKER` ]; then
		echo "$CHECKER not found"
		exit
	fi
	$PUSH_SWAP $ARG | $CHECKER $ARG
elif [ "$2" = "cnt" ]; then
	$PUSH_SWAP $ARG | wc -l
elif [ "$2" = "cmd" ]; then
	$PUSH_SWAP $ARG
fi
