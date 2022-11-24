#!/usr/bin/env bash

# A wrapper that calls dfu-util with the right kiibohd.dfu.bin file built with build-kll.sh

MY_DIR=$(dirname "$0")

# Load local variables
source $MY_DIR/.env

echo ''
echo '============ Start flashing my whitefox keyboard ============='
echo ''

dfu-util -D $FIRMWARE_DIR/$FLASH_TARGET

echo ''
echo '============ Finished flashing my whitefox keyboard ============='
echo ''
