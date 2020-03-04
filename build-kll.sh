#!/usr/bin/env bash

# A wrapper over the target build command 'whitefox.bash'

MY_DIR=$(dirname "$0")

# Load local variables
source $MY_DIR/.env

fast_mode=false

while getopts ":f" opt; do
    case $opt in
        f)
            fast_mode=true
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
    esac
done

echo ''
echo '============ Building KLL Firmware ============='
echo ''

cd $MY_DIR/$KLL_BUILD_PATH

if [ "$fast_mode" = false ] ; then
    echo 'fast_mode is off by default. Install dependencies...'
    pipenv install
else
    echo 'fast_mode is on. Skip install dependencies'
fi

pipenv run ./whitefox.bash

echo "============ Moving Firmware from [$(ls $KLL_BUILD_FIRMWARE_FILE)] to [$FIRMWARE_DIR] ==========="
mv $KLL_BUILD_FIRMWARE_FILE $FIRMWARE_DIR

echo ''
echo '============ Finished building KLL Firmware ============='
echo ''
