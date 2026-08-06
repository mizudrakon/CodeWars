#!/bin/bash
if [ -e run ]; then
    rm run
fi
g++ -std=c++23 -Wall -Wextra $1 -o run
if [ -e run ]; then
    ./run
fi