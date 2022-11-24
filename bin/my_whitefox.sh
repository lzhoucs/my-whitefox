#!/usr/bin/env zsh
KBD=$(dirname "$0")/..
source $KBD/venv/bin/activate

if [ "$1" = "compile" ]; then
	qmk compile
elif [ "$1" = "flash" ]; then
	qmk flash
else
	echo "Specify either compile or flash as argument"
	exit 0
fi
