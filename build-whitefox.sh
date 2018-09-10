#!/usr/bin/env bash

# A wrapper over the target build command 'whitefox.bash'

echo ''
echo '============ Start building my whitefox keyboard ============='
echo ''

cd ../kiibohd-controller/Keyboards

./whitefox.bash

echo ''
echo '============ Finished building my whitefox keyboard ============='
echo ''
