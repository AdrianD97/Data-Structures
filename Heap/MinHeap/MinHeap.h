#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "../Heap.h"

// create an empty min heap (the method is a kind of C++ constructor)
MinHeap* createEmptyMinHeap(int size, int (*compare)(void*, void*)) {
	return createEmptyHeap(size, compare);
}

// add an item to min heap
void addItemToMinHeap(MinHeap* min_heap, void* value) {
	addItemToHeap(min_heap, value, MIN_HEAP);
}

// get root of the min heap
void* getMinHeapRoot(const MinHeap* min_heap) {
	return getHeapRoot(min_heap);
}

// remove and return root of the min heap
void* removeMinHeapRoot(MinHeap* min_heap) {
	return removeHeapRoot(min_heap, MIN_HEAP);
}

// free used memory
void freeMinHeapMemory(MinHeap* min_heap) {
	freeHeapMemory(min_heap);
}

#endif // MIN_HEAP_H
