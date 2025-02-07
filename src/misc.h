#ifndef MISC_H
#define MISC_H 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define u8t uint8_t
#define u16t uint16_t
#define u32t uint32_t
#define u64t uint64_t
#define any void*

#define DEBUG false
#define POOL_SIZE 1024


typedef struct{
  void** address;
  int size;
  int pointer;
}tb_gc;

extern tb_gc general_gc;


typedef struct{
  char*string;
  size_t len;
}StringBuilder;


typedef struct{
  char** buffer;
  int len;
}matrix2d;


#define MALLOC(args,ret_ptr, cast)\
    ret_ptr = (cast)malloc(args);\
    push_address(&general_gc, (void*)ret_ptr);

#define DINFO(string) \
    printf("[ DEBUG INFO ] : "string"\n");

#define INFO(string) \
    printf("[ INFO ] : "string"\n");

#define TODO(string)\
    printf("- [ TODO ] -> "string"\n");

void init_gc(tb_gc * gc);
void free_trash(tb_gc * gc);
void push_address(tb_gc*gc, void* address);
StringBuilder* read_file(char*path);
matrix2d* split_string(StringBuilder* sb);
void write_file(StringBuilder *sb, char *path);

#ifndef MISC_IMP
#define MISC_IMP

#endif

#endif 
