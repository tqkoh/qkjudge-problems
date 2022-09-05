#!/bin/bash

if ! [ -d in ]; then
    echo "directory 'in' doe's not exists."
    exit 1
fi
if ! [ -d out ]; then
    echo "directory 'out' doe's not exists."
    exit 1
fi
if ! g++ -std=c++17 -Wall -Wextra -O2 -o val validator_ebi/val_ebi.cpp; then
    echo "compile failed."
    exit 1
fi
for i in in/*; do
    if ! ./val < $i; then
        echo "validation failed : $i"
        exit 1
    fi
done
rm val
for i in `ls in`; do
    if ! [ -f out/${i//in/out} ]; then
        echo "extra input file : $i"
        exit 1
    fi
done
for i in `ls out`; do
    if ! [ -f in/${i//out/in} ]; then
        echo "extra output file : $i"
        exit 1
    fi
done
echo "validated successfully."