#!/usr/bin/env bash

sudo apt install clang-format-15

mkdir tools
cd tools
if [ ! -f esbmc-kind.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/esbmc-kind.zip
    rm -rf esbmc
    unzip esbmc-kind.zip
fi
if [ ! -f uautomizer.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/uautomizer.zip
    rm -rf uautomizer
    unzip uautomizer.zip
fi

cd ../
