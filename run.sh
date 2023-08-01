#!/usr/bin/env bash

if [ -d /barrett/scratch/haozewu/vmware/GPT_MC ]
then
    python3 /barrett/scratch/haozewu/vmware/GPT_MC/src/run.py $@
else
    python3 ./src/run.py $@
fi

