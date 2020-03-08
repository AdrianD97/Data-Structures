#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "../Heap.h"

// create an empty max heap (the method is a kind of C++ constructor)
MaxHeap* createEmptyMaxHeap(int size, int (*compare)(void*, void*)) {
	return createEmptyHeap(size, compare);
}

// add an item to max heap
void addItemToMaxHeap(MaxHeap* max_heap, void* value) {
	addItemToHeap(max_heap, value, MAX_HEAP);
}

// get root of the max heap
void* getMaxHeapRoot(const MaxHeap* max_heap) {
	return getHeapRoot(max_heap);
}

// remove and return root of the max heap
void* removeMaxHeapRoot(MaxHeap* max_heap) {
	return removeHeapRoot(max_heap, MAX_HEAP);
}

// free used memory
void freeMaxHeapMemory(MaxHeap* max_heap) {
	freeHeapMemory(max_heap);
}

#endif // MAX_HEAP_H