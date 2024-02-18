#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/*
	You are free to use any data type you like in this file.
    However, other than the five functions declared in "utils.h",
    DO NOT create any other functions.
	
*/

int cmpr_int(void* a, void* b) {
    // Cast void* to int* and get the value
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    // Compare the integers
    if (int_a < int_b) return -1;
    else if (int_a > int_b) return 1;
    else return 0;
}

int cmpr_float(void* a, void* b) {
    // Cast void* to float* and get the value
    float float_a = *(float*)a;
    float float_b = *(float*)b;

    // Compare the floats
    if (float_a < float_b) return -1;
    else if (float_a > float_b) return 1;
    else return 0;
}

void print_int(void* p) {
    printf("%d\n", *(int*)p);
}

void print_float(void* p) {
    printf("%f\n", *(float*)p);
}

	
void* read_array(char* filename, char* format, size_t* len) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Determine the size of the type to be read
    size_t type_size = (format[1] == 'd') ? sizeof(int) : sizeof(float);

    // Allocate memory for the array
    void *array = malloc(type_size);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        exit(1);
    }

    // Read elements from the file
    *len = 0;
    while (!feof(file)) {
        // Resize the array to accommodate the new element
        void *temp = realloc(array, type_size * (*len + 1));
        if (temp == NULL) {
            fprintf(stderr, "Memory reallocation failed.\n");
            free(array);
            fclose(file);
            exit(1);
        }
        array = temp;

        // Read the next element
        if (fscanf(file, format, (char*)array + type_size * *len) == 1) {
            (*len)++;
        } else {
            // Handle read error or end of file
            break;
        }
    }

    fclose(file);
    return array;
}