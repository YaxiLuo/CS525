#include "insertion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	We emphasize this: because this is a generic implementation, in insertion.c you must not use if-else to
	discriminate different data types in your code. Your code must be able to deal with any data type possible.
	Therefore, we limit the usage of the following primitive types:
	- int or size_t: only allowed as loop iterators;
	- char or u_int8_t: can be used as you wish;
	- Types that are used in the declarations of iSort() and iPrint(): feel free to use them for their _original_
      purpose;
	- All other types are not allowed to appear in insertion.c: no exceptions, no matter if you actually used
	  them, or what purpose it is. Once it appears, you will receive 30% reduction of the homework.

	You are free to create helper functions only in insertion.c; you must declare and implement them in the
    .c file instead of the header files. Do not change any of the header files.
	
*/


void iSort(void* base, size_t nel, size_t width, int (*compare)(void*, void*)) {
    char* temp = malloc(width);
    if (temp == NULL) {
        // Handle memory allocation error
        fprintf(stderr, "Memory allocation failed in iSort.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 1; i < nel; i++) {
        memcpy(temp, (char*)base + i * width, width);
        size_t j = i;
        while (j > 0 && compare((char*)base + (j - 1) * width, temp) > 0) {
            memcpy((char*)base + j * width, (char*)base + (j - 1) * width, width);
            j--;
        }
        memcpy((char*)base + j * width, temp, width);
    }

    free(temp);
}


void iPrint(void* base, size_t nel, size_t width, void (*print)(void*)) {
	for (size_t i = 0; i < nel; i++) {
		print((char*)base + i * width);
	}
}
