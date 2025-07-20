#include <stdio.h>
#include <stdlib.h>
#include "misc.h"


Arena_header ah = {0};

#define msb_alloc() sb_alloc(&ah);
#define msb_append(sb, string) sb_append(&ah, sb, string);

int main(){
  StringBuilder* sb_1 = msb_alloc();
  StringBuilder* sb_2 = msb_alloc();
  char* test_string_1 = "Hello from ";
  char* test_string_2 = "String Builder Allocator";
  msb_append(sb_1, test_string_1);
  msb_append(sb_1, test_string_2);
  printf("Content of sb_1: %s\n", sb_1->string);
  char* test_string_3 = "\n\n\
    La bocca sollevò dal fiero pasto\n\
    quel peccator, forbendola a' capelli\n\
    del capo ch'elli avea di retro guasto.\n\
    \n\
    Poi cominciò: 'Tu vuo’ ch’io rinovelli\n\
    disperato dolor che ’l cor mi preme\n\
    già pur pensando, pria ch’io ne favelli.\n\
    \n\
    Ma se le mie parole esser dien seme\n\
    che frutti infamia al traditor ch’i’ rodo,\n\
    parlare e lagrimar vedrai insieme.' ....\n\
    ";

  msb_append(sb_2, test_string_3);
  printf("Content of sb_2: %s\n", sb_2->string);
  printf("\nSize and len of sb_1: len = %d, size = %zu\n", sb_1->len, sb_1->size);
  printf("\nSize and len of sb_2: len = %d, size = %zu\n", sb_2->len, sb_2->size);
 
  arena_free(&ah);
  return 0;
}
