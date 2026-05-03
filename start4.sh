#!/bin/sh
g++ -fPIC -shared -O3 -march=native -mavx2 $1 -o $2