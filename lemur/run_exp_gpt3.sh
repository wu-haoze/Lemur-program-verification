#!/usr/bin/env bash

name=$1
bname=$(basename $name)

echo $name
echo $bname

working_dir=data_sv_comp_gpt3_
mkdir $working_dir

timeout 900 ./run.sh "$name".yml --learn -v all --per-instance-timeout 30 -w $working_dir --model gpt-3.5-turbo
