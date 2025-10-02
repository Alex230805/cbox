#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4 // in bytes   
#define PAGE_NUMBER 64 // number of pages per arena. The length of the arena would be PAGE_SIZE*PAGE_NUMBER.

#include "misc.h"

Arena_header arenah = {0};

int main(){
  StringBuilder sb_foo = {0};

  static char* lorem = "Lorem ipsum odor amet, consectetuer adipiscing elit. Vivamus placerat suscipit litora quam tortor finibus blandit a praesent? Quisque libero sodales quam sit est turpis. Pharetra rhoncus fringilla senectus convallis tristique nam nostra amet. Platea nam efficitur potenti molestie semper sem maecenas viverra. Posuere odio non eleifend tristique vehicula suspendisse eros morbi.\
\
Proin fringilla id aenean venenatis, vel ligula consectetur. Vivamus conubia massa dis rhoncus mi penatibus dictum. Rhoncus vulputate rhoncus fames at iaculis at. Nisi libero nisi tempor erat blandit mi pharetra. Vehicula et pretium mus; cursus facilisi mus neque habitant. Dictum lorem fusce varius bibendum fermentum mattis mauris mollis lacinia. Eget nunc torquent per natoque euismod justo a!\
\
Libero consectetur class suspendisse eget nulla consectetur semper elit. Praesent posuere litora posuere etiam mollis egestas; sociosqu duis. Nascetur aptent dictum etiam finibus fringilla sit phasellus; adipiscing posuere. Himenaeos ligula curae curabitur, odio amet id a dignissim eros. Aptent nullam hendrerit phasellus hac sollicitudin. Velit cras dis vehicula diam integer ligula. Ornare pellentesque ullamcorper orci dapibus primis lacus. Placerat dapibus purus molestie efficitur nostra finibus suspendisse quisque non. Tortor lacus curae vulputate curae tincidunt et scelerisque.\
\
Venenatis tempor auctor etiam laoreet curae; eros sodales lobortis. Erat interdum in duis pellentesque rutrum condimentum. Mus mattis tincidunt elementum id per leo dapibus? Iaculis lobortis malesuada facilisis blandit; nunc placerat. Montes pulvinar proin augue vel id iaculis. Metus metus hendrerit ullamcorper morbi; duis magnis parturient velit.\
\
Cursus montes phasellus rhoncus duis placerat congue convallis ullamcorper. Aliquet ac mollis suscipit pellentesque faucibus vulputate. Euismod ante placerat torquent placerat fusce cras sociosqu. Lectus lorem enim interdum nullam dictum nascetur accumsan ridiculus. Pellentesque sociosqu potenti primis natoque iaculis leo. Id massa sem sagittis dapibus bibendum posuere parturient est. Quis magna ut nullam curae dui nostra class integer. Semper natoque magnis odio tincidunt imperdiet velit eros torquent erat? Torquent taciti faucibus senectus elementum metus libero.";

  sb_foo.len = strlen(lorem);
  printf("Lorem len: %d\n", sb_foo.len);
  sb_foo.string = (char*)arena_alloc(&arenah, sizeof(char)*sb_foo.len);
  strcpy(sb_foo.string, lorem);

  printf("Current allocateed array's content: \n\n%s\n", sb_foo.string);
  
  char** test_array = {0};
  #define DEFAULT_SIZE 2;
  size_t test_size = DEFAULT_SIZE;
  size_t test_tracker = 0;
  test_array = (char**)arena_alloc(&arenah,sizeof(char*)*test_size);
  for(size_t i=0;i<10; i++){
    char* word = (char*)arena_alloc(&arenah, sizeof(char));
    *word = i+65;
    dapush(arenah, test_array, test_tracker, test_size, char*, word);
  }
  printf("\nContent of the append: \n");
  for(size_t i=0;i<test_tracker; i++){
    printf("cell %zu: %s\n", i, test_array[i]);
  }
  printf("\n");
  arena_free(&arenah);
  return 0;
}
