#!bin/sh 

gcc -I./src -I. -c ./src/misc.c -o misc.o
gcc arena_test.c -o arena_test -I./src -L. -l:misc.o 
gcc string_builder_test.c -o string_builder_test -I./src -L. -l:misc.o 
gcc notify_macro.c -o notify_macro -I./src -L. -l:misc.o 
gcc error_handler_test.c -o error_handler_test -I./src -L. -l:misc.o
