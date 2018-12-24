#!/usr/bin/env bash

# A wrapper that calls dfu-util with the right kiibohd.dfu.bin file built with './build-whitefox.sh'
BuildDir=darwin18.MyWhiteFoxBuild.gcc.ninja

echo ''
echo '============ Start flashing my whitefox keyboard ============='
echo ''

dfu-util -D ../kiibohd-controller/Keyboards/${BuildDir}/kiibohd.dfu.bin

echo ''
echo '============ Finished flashing my whitefox keyboard ============='
echo ''
