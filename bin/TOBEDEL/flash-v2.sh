#!/usr/bin/env bash

MY_DIR=$(dirname "$0")

# Load local variables
source $MY_DIR/.env

# the following is copied from controller/LoadFile/load.dfu
if type dfu-util &>/dev/null; then
	echo "Waiting for device..."
	while true; do
		dfu-util -l | grep -q "Kiibohd DFU"
		if [ $? -eq 0 ]; then
			break
		fi
		sleep 0.1
	done
    dfu-util -D $FIRMWARE_DIR/$FLASH_TARGET
	EXIT_STATUS=$?
else
	echo "dfu-util is required to reprogram the device"
	exit 3
fi

