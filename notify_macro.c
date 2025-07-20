#include <stdio.h>
#include <stdlib.h>
#include "misc.h"


int main(){
  printf("Testing custom error messages\n"); 

  TODO("Example of todo", NULL);
  DINFO("Example of debug information", NULL);
  NOTY("Le noty","Example of notification system", NULL);
  WARNING("This is a warning, be carefull!!", NULL);
  ERROR("Example of error", NULL);
    
  return 0;
}
