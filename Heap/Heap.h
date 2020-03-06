#ifndef HEAP_H
#define HEAP_H

#include "utils.h"

// create an empty Heap (the method is a kind of C++ constructor)
Heap* createEmptyHeap(int size, int (*compare)(void*, void*)) {
	Heap* heap = (Heap*)malloc(sizeof(Heap));

	heap->size = size;
	heap->index = 0;
	heap->compare = compare;
	heap->arr = (void**)calloc((size + 1), sizeof(void*));

	return heap;
}

// add an item to Heap
void pushUp(Heap* heap, int type) {
	int index = heap->index;
	int parent, result = 0;
	void* tmp;

	do {
		parent = index / 2;
		
		if (parent == 0) {
			break;
		}

		result = heap->compare(heap->arr[index], heap->arr[parent]);

		if (type == 1) { // heap is min heap
			if (result >= 0) {
				break;
			}
		} else { // heap is max heap
			if (result <= 0) {
				break;
			}
		}

		tmp = heap->arr[index];
		heap->arr[index] = heap->arr[parent];
		heap->arr[parent] = tmp;
		index = parent;
	} while (1);
}

/*
	type = 1 -> heap is a min heap
	type = 0 -> heap is a max heap
*/
void addItemToHeap(Heap* heap, void* value, int type) {
	if (!heap || (type != 0 && type != 1)) {
		return;
	}

	// check if Heap is full
	if (heap->index + 1 > heap->size) {
		return;
	}

	heap->arr[++heap->index] = value;
	pushUp(heap, type);
}

// get root of the heap
void* getHeapRoot(const Heap* heap) {
	if (heap->index == 0) {
		return NULL;
	}

	return heap->arr[ROOT];
}

// remove and return root of the heap
void pushDown(Heap* heap, int type) {
	if (heap->index == 0) {
		return;
	}

	int index = ROOT, result;
	int child_ind, result_;
	void* tmp;

	do {
		if (2 * index <= heap->index) {
			if (2 * index + 1 > heap->index) {
				result = heap->compare(heap->arr[index], heap->arr[2 * index]);
				child_ind = 2 * index;
			} else {
				result_ = heap->compare(heap->arr[2 * index], heap->arr[2 * index + 1]);

				if (type == 1) { // heap is min heap
					child_ind = (result_ < 0) ? (2 * index) : (2 * index + 1);
				} else { // heap is max heap
					child_ind = (result_ > 0) ? (2 * index) : (2 * index + 1);
				}

				result = heap->compare(heap->arr[index], heap->arr[child_ind]);
			}

			if (type == 1) { // heap is min heap
				if (result <= 0) {
					break;
				}
			} else { // heap is max heap
				if (result >= 0) {
					break;
				}
			}

			tmp = heap->arr[index];
			heap->arr[index] = heap->arr[child_ind];
			heap->arr[child_ind] = tmp;
			index = child_ind;
		} else {
			break;
		}

	} while (1);
}

/*
	type = 1 -> heap is a min heap
	type = 0 -> heap is a max heap
*/
void* removeHeapRoot(Heap* heap, int type) {
	if (!heap || !heap->arr || heap->index == 0 || (type != 0 && type != 1)) {
		return NULL;
	}

	void* tmp = heap->arr[ROOT];
	heap->arr[ROOT] = heap->arr[heap->index];
	heap->arr[heap->index] = tmp;

	--heap->index;
	pushDown(heap, type);

	return tmp;
}

// free used memory
void freeHeapMemory(Heap* heap) {
	if (!heap || !heap->arr) {
		return;
	}

	free(heap->arr);
	heap->arr = NULL;
}

#endif // HEAP_H