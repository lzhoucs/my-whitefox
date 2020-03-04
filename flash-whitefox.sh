#!/usr/bin/env bash

# A wrapper that calls dfu-util with the right kiibohd.dfu.bin file built with build-kll.sh

MY_DIR=$(dirname "$0")

# Load local variables
source $MY_DIR/.env

echo ''
echo '============ Start flashing my whitefox keyboard ============='
echo ''

dfu-util -D $MY_DIR/bins/$KLL_BIN_NAME

echo ''
echo '============ Finished flashing my whitefox keyboard ============='
echo ''
