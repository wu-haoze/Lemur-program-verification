#!/usr/bin/env bash

if [ -d /barrett/scratch/haozewu/vmware/GPT_MC ]
then
    python3 -u /barrett/scratch/haozewu/vmware/GPT_MC/src/run.py $@
else
    python3 -u ./src/run.py $@
fi

