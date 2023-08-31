import os
import shutil


with open("both_timed_out.csv", 'r') as in_file:
    for line in in_file.readlines():
        src1 = f"./benchmarks/short_single_assertion_with_loop_all/c/{line.strip()[:-4]}.yml"
        src2 = f"./benchmarks/short_single_assertion_with_loop_all/c/{line.strip()[:-4]}.c"
        src3 = f"./benchmarks/short_single_assertion_with_loop_all/c/{line.strip()[:-4]}.i"
        dst = "./benchmarks/short_single_assertion_with_loop/c/"
        try:
            shutil.copy(src1, dst)
        except:
            print(src1, dst)
        try:
            shutil.copy(src2, dst)
        except:
            print(src2, dst)
        try:
            shutil.copy(src3, dst)
        except:
            print(src3, dst)
