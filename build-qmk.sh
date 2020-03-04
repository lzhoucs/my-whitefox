#!/usr/bin/env bash

# A wrapper over the target build command 'make whitefox:lzhoucs'

MY_DIR=$(dirname "$0")

# Load local variables
source $MY_DIR/.env

echo ''
echo '============ Build QMK Firmware ============='
echo ''

cd $MY_DIR/$QMK_REPO
make whitefox:$QMK_KEYMAPS_NAME

echo "============ Moving Firmware from [$QMK_BIN_NAME] to [$FIRMWARE_DIR] ==========="
mv $QMK_BIN_NAME $FIRMWARE_DIR

echo ''
echo '============ Finished building QMK Firmware ============='
echo ''
