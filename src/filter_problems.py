import csv

def parse_csv_to_dict(csv_filename):
    result_dict = {}

    with open(csv_filename, 'r') as csvfile:
        csv_reader = csv.DictReader(csvfile)
        
        for row in csv_reader:
            benchmark = row['benchmark']
            config = row['config']
            if int(row['sat']) > 0:
                solved = "sat"
            elif int(row["unsat"]) > 0:
                solved = "unsat"
            else:
                solved = "unknown"
 
            if benchmark not in result_dict:
                result_dict[benchmark] = {}
            
            result_dict[benchmark][config] = solved
    
    return result_dict

# Replace 'input.csv' with the actual CSV filename
csv_filename = 'result.csv'
benchmark_to_results = parse_csv_to_dict(csv_filename)

short_benchmarks = list(map(lambda x: "/".join(x.strip().split("/")[-2:]), open("benchmarks/benchmark_set_reach_safety_short").readlines()))

for benchmark, results in benchmark_to_results.items():
    if benchmark in short_benchmarks:
        if results["esbmc_default"] == "unknown":# and \
           #(results["uautomizer_bitprecise"] != "unknown"
        #    or results["uautomizer_default"] != "unknown"):
        #    print(benchmark)
        #if (results["cbmc_default"] != "unknown" or results["esbmc_default"] != "unknown") and \
        #if results["uautomizer_default"] == "unknown" and results["uautomizer_bitprecise"] == "unknown":
            print(benchmark)
