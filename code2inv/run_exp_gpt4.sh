#!/usr/bin/env bash

name=$1
bname=$(basename $name)


echo $name
echo $bname

working_dir=data_sv_comp_gpt4_
mkdir $working_dir

timeout 600 ./run.sh "$name".yml --learn -v all --per-instance-timeout 30 -w $working_dir --model gpt-4
