#ifndef UTILS_H
#define UTILS_H

#define MIN_HEAP 1
#define MAX_HEAP 0

#define ROOT 1

typedef struct {
	int size;
	int index;
	int (*compare)(void*, void*);
	void** arr;
} Heap;

typedef Heap MinHeap;
typedef Heap MaxHeap;

#endif // UTILS_H
