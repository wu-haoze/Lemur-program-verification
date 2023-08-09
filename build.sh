#!/usr/bin/env bash

mkdir benchmarks
cd benchmarks
if [ ! -f sv-benchmarks-svcomp23.zip ]
then
    wget https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks/-/archive/svcomp23/sv-benchmarks-svcomp23.zip
    rm -rf sv-benchmarks-svcomp23
    unzip sv-benchmarks-svcomp23.zip
    cd sv-benchmarks-svcomp23/c/
    while read p ; do for file in $p; do echo $(realpath $file); done; done < ../../ReachSafety.txt  > ../../benchmark_set_reach_safety
    cd ../../
fi
cd ../

mkdir tools
cd tools
if [ ! -f esbmc-kind.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/esbmc-kind.zip
    rm -rf esbmc
    unzip esbmc-kind.zip
fi
if [ ! -f cbmc.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/cbmc.zip
    rm -rf cbmc
    unzip cbmc.zip
fi
if [ ! -f sl2.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/2ls.zip
    rm -rf sl2
    unzip sl2.zip
fi
if [ ! -f uautomizer.zip ]
then
    wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/raw/svcomp23/2023/uautomizer.zip
    rm -rf uautomizer
    unzip uautomizer.zip
fi

cd ../
