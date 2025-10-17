#include <stdio.h>
#include <stdlib.h>
#include "misc.h"


Arena_header ah = {0};
StringBuilder sb_0 = {0};


int main(){

	sb_append(&sb_0, "\n=====================================================\n");
	sb_append(&sb_0, "String builder showcase function and example program\n");
	sb_append(&sb_0, "=====================================================\n\n");
	printf("%s", sb_0.string);
	free(sb_0.string);

	StringBuilder* sb_1 = sb_alloc();
	StringBuilder* sb_2 = sb_alloc();
	char* test_string_1 = "Hello from ";
	char* test_string_2 = "String Builder Memory Allocator";
	sb_append(sb_1, test_string_1);
	sb_append(sb_1, test_string_2);
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

	sb_append(sb_2, test_string_3);
	printf("Content of sb_2: %s\n", sb_2->string);
	printf("\nSize and len of sb_1: len = %d, size = %zu\n", sb_1->len, sb_1->size);
	printf("\nSize and len of sb_2: len = %d, size = %zu\n", sb_2->len, sb_2->size);

	// StringBuilder allocated with sb_alloc must be deallocated
	free(sb_1->string);
	free(sb_2->string);
	free(sb_1);
	free(sb_2);

	sb_1 = arena_sb_alloc(&ah);
	sb_2 = arena_sb_alloc(&ah);

	arena_sb_append(&ah,sb_1, test_string_1);
	arena_sb_append(&ah,sb_1, "String Builder Arena Allocator");
	printf("Content of sb_1: %s\n", sb_1->string);
	arena_sb_append(&ah,sb_2, test_string_3);
	printf("Content of sb_2: %s\n", sb_2->string);
	printf("\nSize and len of sb_1: len = %d, size = %zu\n", sb_1->len, sb_1->size);
	printf("\nSize and len of sb_2: len = %d, size = %zu\n", sb_2->len, sb_2->size);


	// StringBuilder allocated with the arena allocator doesn't need an individual free
	arena_free(&ah);
	return 0;
}
