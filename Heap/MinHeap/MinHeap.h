#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "../utils.h"

MinHeap* createEmptyMinHeap(int size, int (*compare)(void*, void*)) {
	MinHeap* min_heap = (MinHeap*)malloc(sizeof(MinHeap));

	min_heap->size = size;
	min_heap->index = 0;
	min_heap->compare = compare;
	min_heap->arr = (void**)calloc((size + 1), sizeof(void*));

	return min_heap;
}

#endif // MIN_HEAP_H
