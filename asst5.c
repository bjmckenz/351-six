#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heap.h"

/*
Assignment 5: integer minheap
*/

unsigned long long rand_between(unsigned long long min,
                                unsigned long long max) {
    unsigned long long range = max - min;
    return min + (rand() % range);
}

void test_heap(void) {
    heap_t *heap = heap_create(200);
    for (heap_key_t ix = 0; ix < 20; ix++) {
        heap_key_t key = rand_between(0, 1000);
        heap_insert(heap, key, (heap_value_t)key);
        heap_print(heap);
    }
    for (int ix = 0; ix < 10; ix++) {
        heap_key_t key = (heap_key_t)heap_remove_min(heap);
        printf("Removed %llu\n", key);
        heap_print(heap);
    }
    exit(0);
}
int main(int argc, char *argv[]) {
    srand(time(NULL));

    test_heap();
}
