#include <stdio.h>
#include <stdlib.h>

#include "misc.h"

int main(){
	error_handler eh = {0};
	
	char test_string[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse nisi ex, molestie nec pulvinar sit amet, laoreet in enim.";

	error_push_error(&eh,"Unable to open file location",15, 69, &test_string[2], 5);
	error_push_error(&eh,"Unable to open file location",34, 420, &test_string[5], 7);
	error_push_error(&eh,"Unable to open file location",35, 42069, &test_string[0],2);

	

	printf("\nPrinting dummy errors with full settings: \n");
	error_print_error(&eh, (print_set){true, true,true,true,true, true, true});
	
	printf("\nPrinting dummy errors with all setting disabled: \n");
	error_print_error(&eh, (print_set){false, false, false, false, false, false, false});
	
	printf("\nPrinting dummy errors without line reference : \n");
	error_print_error(&eh, (print_set){true, true,true,true,true, false, false});
	return 0;
}
