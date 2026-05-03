#!/bin/sh
g++ -fPIC -shared -O3 -march=native $1 -o $2