#!/usr/bin/env bash

# A wrapper over the target build command 'whitefox.bash'
BuildDir=darwin18.MyWhiteFoxBuild.gcc.ninja
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
echo '============ Start building my whitefox keyboard ============='
echo ''

cd ../kiibohd-controller/Keyboards

if [ "$fast_mode" = false ] ; then
    echo 'fast_mode is off by default. Install dependencies...'
    pipenv install
else
    echo 'fast_mode is on. Skip install dependencies'
fi

pipenv run ./whitefox.bash

mv ${BuildDir}/kiibohd.dfu.bin ../../my-whiteFox-TrueFox/

echo ''
echo '============ Finished building my whitefox keyboard ============='
echo ''
