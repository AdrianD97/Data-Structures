#ifndef UTILS_H
#define UTILS_H

typedef struct {
	int size;
	int index;
	int (*compare)(void*, void*);
	void** arr;
} Heap;

typedef Heap MinHeap;
typedef Heap MaxHeap;

#endif // UTILS_H
