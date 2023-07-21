#!/usr/bin/env bash

filename=$(realpath $1)

cd /home/haozewu/Projects/vmware/GPT_MC/UAutomizer-linux
shift

echo python3 ../src/runUAutomizer.py $filename $@
