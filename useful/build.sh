#!/bin/bash

g++ -Wall -O2 -std=c++14 -static -pipe $1 -Wextra && ./a.out
