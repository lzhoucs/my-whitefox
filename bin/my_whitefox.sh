#!/usr/bin/env zsh
KBD=$(dirname "$0")/..
source $KBD/venv/bin/activate

if [[ $1 =~ ^(compile|flash|lint|console)$ ]]; then
	qmk $1
else
	echo "Specify compile|flash|lint|console as argument"
	exit 0
fi
