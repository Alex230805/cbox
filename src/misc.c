#define MISC_IMP


#include <misc.h>


void init_gc(tb_gc *gc){
  gc->address = (void**)malloc(sizeof(void*)*POOL_SIZE);
  gc->size = POOL_SIZE;
  gc->pointer = 0;
}

void free_trash(tb_gc*gc){
  for(int i=0;i<gc->pointer;i++){
    free(gc->address[i]);
    gc->address[i] = NULL;
  }
}

void push_address(tb_gc*gc, void* address){
  if(gc->pointer+1 >= POOL_SIZE){
    fprintf(stderr, "garbage collector full of trash man, check your code, this is unacceptable!\n");
    exit(1);
  }else{
    gc->address[gc->pointer] = address;
    gc->pointer += 1;
  }
}



StringBuilder* read_file(char*path){
  if(DEBUG) DINFO("Reading file"); 
  StringBuilder *sb;
  MALLOC(sizeof(StringBuilder), sb, StringBuilder*);
  FILE * fp;
  fp = fopen(path, "r");
  bool end = false;
  int len = 0;
  if(fp == NULL){
    fprintf(stderr, "Unable to open instruction file: %s : %d\n", strerror(errno), errno);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  sb->len = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  MALLOC(sizeof(char)*sb->len+1, sb->string, char*);
  for(size_t i=0;i<sb->len && !end;i++){
    char c = fgetc(fp);
    if(c == EOF){
      end = true;
    }else{
      sb->string[i] = c;
      len++;
    }
  }
  sb->string[len] = '\0'; 
  fclose(fp);
  return sb;

}

void write_file(StringBuilder *sb, char *path){
  if(DEBUG) DINFO("Writing file"); 
  FILE * fp;
  fp = fopen(path, "w");
  if(fp == NULL){
    fprintf(stderr, "Unable to open instruction file: %s : %d\n", strerror(errno), errno);
    exit(1);
  }
  fwrite(sb->string, 1, sb->len, fp);
  fclose(fp);
}




matrix2d* split_string(StringBuilder* sb){
  if(DEBUG) DINFO("Splitting string into matrix2d"); 
  int start = 0;
  int count = 0;
  bool end = false;
  int col = 0;
  matrix2d* buffer;
  int chars = 0; 
  MALLOC(sizeof(matrix2d),buffer,  matrix2d*);
  
  if(sb->len == 0){
    buffer->len = 0;
    buffer->buffer = NULL;
    return buffer;
  }
  
  for(size_t i=0;i<sb->len;i++){
    if(sb->string[i] == ';') col += 1;
  }
  MALLOC(sizeof(matrix2d),buffer,  matrix2d*);
  MALLOC(sizeof(char*)*col,buffer->buffer,  char**);

  for(int j=0;j<col;j++){
    for(size_t i=0;i<sb->len && !end;i++){
      if(sb->string[i+start] != ';'){
        count +=1;
      }else{
        end = true;
      }
    }
    end = false;
    MALLOC(sizeof(char)*count+1,buffer->buffer[j],  char*);
    for(int i=start;i<start+count;i++){
      if(sb->string[i] != ' ' && sb->string[i] != '\n'){
        buffer->buffer[j][chars] = sb->string[i];
        chars++;
      }
    }
    buffer->buffer[j][chars] = '\0';
    chars = 0;
    buffer->len = col;
    start = start+count+2;
    count = 0;
  }
  return buffer;
}
