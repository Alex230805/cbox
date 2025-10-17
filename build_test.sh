#!bin/sh 

gcc -I./src -I. -c ./src/misc.c -o misc.o
gcc arena_test.c -o arena_test -I./src -L. -lmisc.o 
gcc string_builder_test.c -o string_builder_test -I./src -L. -lmisc.o 
gcc notify_macro.c -o notify_macro -I./src -L. -lmisc.o 
gcc error_handler_test.c -o error_handler_test -I./src -L. -lmisc.o
gcc temp_allocator_test.c -o temp_allocator_test -I./src -L. -lmisc.o
