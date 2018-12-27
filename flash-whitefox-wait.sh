#!/usr/bin/env bash

# Load via dfu-util
# Used for McHCK based uCs
if type dfu-util &>/dev/null; then
	echo "Waiting for device..."
	while true; do
		dfu-util -l | grep -q "Kiibohd DFU"
		if [ $? -eq 0 ]; then
			break
		fi
		sleep 0.1
	done
	dfu-util -D kiibohd.dfu.bin
	EXIT_STATUS=$?
else
	echo "dfu-util is required to reprogram the device"
	exit 3
fi

