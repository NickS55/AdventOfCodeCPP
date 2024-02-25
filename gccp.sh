#/bin/sh

echo compiling C++ VERSION 17 using -ansi -pedantic-errors -Wall w/ debugging info
g++ -std=c++17 -g -pedantic-errors -Wall $1 $2 $3
