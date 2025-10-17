#include <stdio.h>
#include <stdlib.h>
#include "misc.h"


int iterations = 64;

int main(){
	const char* dummy = "Thi is a test, if you can read this then the temp allocator is fully working!\n";
	char* test = (char*)temp_alloc(sizeof(char)*strlen(dummy));
	memcpy(test,dummy,sizeof(char)*strlen(dummy));
	printf("%s", test);
	printf("Stress testing the allocator with %d iterations\n",iterations);
	for(int i=0;i<iterations; i++){
		char* buffer = (char*)temp_alloc(sizeof(char)*256);
		char* num = (char*)temp_alloc(sizeof(char)*4);
		buffer[0] = '\0';
		strcpy(buffer, "iteration ");
		sprintf(num, "%d\n", i+1);
		strcat(buffer, num);
		printf("%s", buffer);
	}
	return 0;
}
