#!/usr/bin/env bash

filename=$(realpath $1)

shift
python3 ../src/run.py $filename $@
