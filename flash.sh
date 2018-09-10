#!/usr/bin/env bash

# A wrapper that calls dfu-util with the right kiibohd.dfu.bin file built with './build-whitefox.sh'
echo ''
echo '============ Start flashing my whitefox keyboard ============='
echo ''

# cd ../kiibohd-controller/Keyboards

dfu-util -D ../kiibohd-controller/Keyboards/darwin17.MyWhiteFoxBuild.gcc.ninja/kiibohd.dfu.bin

echo ''
echo '============ Finished flashing my whitefox keyboard ============='
echo ''
