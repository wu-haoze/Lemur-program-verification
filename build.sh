#!/usr/bin/env bash

mkdir benchmarks
cd benchmarks
if [ ! -f sv-benchmarks-main.zip ]
then
    wget https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks/-/archive/main/sv-benchmarks-main.zip
    rm -rf sv-benchmarks-main
    unzip sv-benchmarks-main.zip
fi
cd ../

mkdir tools
cd tools
if [ ! -f cbmc.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/cbmc.zip
    rm -rf cbmc
    unzip cbmc.zip
fi
if [ ! -f uautomizer.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/uautomizer.zip
    rm -rf UAutomizer-linux uautomizer
    unzip uautomizer.zip
    mv UAutomizer-linux uautomizer
fi

cd ../
