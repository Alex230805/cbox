#!bin/sh 


gcc -I./src -I. -c ./src/misc.c -o misc.o
gcc arena_test.c -o arena_test -I./src -L. -l:misc.o 
