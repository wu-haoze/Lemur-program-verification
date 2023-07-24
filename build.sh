#!/usr/bin/env bash



if [ ! -f cbmc.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/cbmc.zip
fi
if [ ! -f uautomizer.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/uautomizer.zip
fi

rm -rf cbmc UAutomizer-linux uautomizer

unzip cbmc.zip
unzip uautomizer.zip
mv UAutomizer-linux uautomizer
