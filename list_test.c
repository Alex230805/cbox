#include <stdio.h>
#include <stdlib.h>
#include "misc.h"


Arena_header ah = {0};
List_header lh = {0};

typedef struct{
	int number;
}number_box;

int main(){
	printf("Testing the bi-linked list integration, first with the Arena allocator\n");
	number_box* box_0 = (number_box*)arena_alloc(&ah,sizeof(number_box));
	number_box* box_1 = (number_box*)arena_alloc(&ah,sizeof(number_box));
	number_box* box_2 = (number_box*)arena_alloc(&ah,sizeof(number_box));
	box_0->number = 69;
	box_1->number = 420;
	box_2->number = 3447;
	arena_list_push(&ah,&lh, box_0);
	arena_list_push(&ah,&lh, box_1);
	arena_list_push(&ah,&lh, box_2);
	for(size_t i=0;i<lh.count;i++){
		printf("Content in pos %zu: %d\n", i,(*(number_box*)list_get_at(&lh,i)).number);
	}
	printf("Testing the bi-linked list integration, now with the standard malloc allocation\n");
	List_header* heap_list = list_alloc();
	list_push(heap_list, box_0);
	list_push(heap_list, box_1);
	list_push(heap_list, box_2);
	for(size_t i=0;i<heap_list->count;i++){
		printf("Content in pos %zu: %d\n", i,(*(number_box*)list_get_at(heap_list,i)).number);
	}
	list_free(heap_list);
	free(heap_list);
	heap_list = NULL;
	arena_free(&ah);
	printf("Note that List_headers can be allocated with dedicated function both inside the arena allocator and with the standard malloc\n");
	return 0;
}
