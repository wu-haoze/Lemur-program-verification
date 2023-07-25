#!/usr/bin/env bash

mkdir benchmarks
cd benchmarks
if [ ! -f sv-benchmarks-svcomp23.zip ]
then
    wget https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks/-/archive/svcomp23/sv-benchmarks-svcomp23.zip
    rm -rf sv-benchmarks-svcomp23
    unzip sv-benchmarks-svcomp23.zip
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

cd ../
