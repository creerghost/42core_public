#!/bin/bash

# List of stack sizes to test
sizes=(3 5 100 500)
runs_count=100
for size in "${sizes[@]}"; do
    echo "Testing size: $size"
    
	for ((i = 0; i < runs_count; i++)); do
		arg=$(shuf -i 1-1000000 -n $size | tr '\n' ' ')
        ops=$(./push_swap $arg | wc -l)
        status=$(./push_swap $arg | ./checker_linux $arg)
        echo "Run $i: $status ($ops ops)"
    done
    echo "-------------------"
done
