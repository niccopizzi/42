#!/bin/bash

for ((n = 1; n <= 3000; n++)); do

    ARG=$(shuf -i 1-10000 -n "$n" | tr '\n' ' ')

    OUTPUT=$(./PmergeMe $ARG)

    if echo "$OUTPUT" | grep -q "Time to process"; then
        echo "n=$n: Array sorted ✅"
    elif echo "$OUTPUT" | grep -q "Not sorted"; then
        echo "n=$n: Array not sorted ❌"
    elif echo "$OUTPUT" | grep -q "params not correct"; then
        echo "n=$n: Parameters are not correct"
    else
        echo "n=$n: Unexpected error ⚠️"
    fi
done