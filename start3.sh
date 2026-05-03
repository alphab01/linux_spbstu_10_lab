#!/bin/sh
g++ -fPIC -shared -O3 -march=native -mavx2 main3.cpp -o lib3.so