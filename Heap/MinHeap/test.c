#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "MinHeap.h"
#include "../../compare_functions/compare_functions_.h"

// test createEmptyMinHeap() function
void testCreateEmptyMinHeap() {
	printf("test createEmptyMinHeap() function.\n");

	int size = 100;

	MinHeap* min_heap = NULL;

	min_heap = createEmptyMinHeap(size, compareIntegers);

	assert(min_heap != NULL);
	assert(min_heap->size == size);
	assert(min_heap->index == 0);
	assert(min_heap->compare == compareIntegers);
	assert(min_heap->arr != NULL);
	assert(min_heap->arr[0] == NULL);
	assert(min_heap->arr[1] == NULL);
	assert(min_heap->arr[size] == NULL);

	freeMinHeapMemory(min_heap);
	free(min_heap);

	printf("\n");
}

// test addItemToMinHeap() function
void testAddItemToMinHeap() {
	printf("test addItemToMinHeap() function.\n");

	int val1 = 1, val2 = 2, val3 = -1;
	int val4 = 5, val5 = 0, val6 = -5;
	int val7 = -2, val8 = 89;

	int size = 7;

	MinHeap* min_heap = NULL;

	min_heap = createEmptyMinHeap(size, compareIntegers);

	addItemToMinHeap(min_heap, (void*)&val1);
	assert(min_heap->index == 1);
	assert(min_heap->arr[1] != NULL);
	assert(*(int*)min_heap->arr[1] == val1);

	addItemToMinHeap(min_heap, (void*)&val2);
	assert(min_heap->index == 2);
	assert(min_heap->arr[2] != NULL);
	assert(*(int*)min_heap->arr[2] == val2);

	addItemToMinHeap(min_heap, (void*)&val3);
	assert(min_heap->index == 3);
	assert(min_heap->arr[3] != NULL);
	assert(*(int*)min_heap->arr[1] == val3);
	assert(*(int*)min_heap->arr[2] == val2);
	assert(*(int*)min_heap->arr[3] == val1);

	addItemToMinHeap(min_heap, (void*)&val4);
	assert(min_heap->index == 4);
	assert(min_heap->arr[4] != NULL);
	assert(*(int*)min_heap->arr[1] == val3);
	assert(*(int*)min_heap->arr[2] == val2);
	assert(*(int*)min_heap->arr[3] == val1);
	assert(*(int*)min_heap->arr[4] == val4);

	addItemToMinHeap(min_heap, (void*)&val5);
	assert(min_heap->index == 5);
	assert(min_heap->arr[5] != NULL);
	assert(*(int*)min_heap->arr[1] == val3);
	assert(*(int*)min_heap->arr[2] == val5);
	assert(*(int*)min_heap->arr[3] == val1);
	assert(*(int*)min_heap->arr[4] == val4);
	assert(*(int*)min_heap->arr[5] == val2);

	addItemToMinHeap(min_heap, (void*)&val6);
	assert(min_heap->index == 6);
	assert(min_heap->arr[6] != NULL);
	assert(*(int*)min_heap->arr[1] == val6);
	assert(*(int*)min_heap->arr[2] == val5);
	assert(*(int*)min_heap->arr[3] == val3);
	assert(*(int*)min_heap->arr[4] == val4);
	assert(*(int*)min_heap->arr[5] == val2);
	assert(*(int*)min_heap->arr[6] == val1);

	addItemToMinHeap(min_heap, (void*)&val7);
	assert(min_heap->index == 7);
	assert(min_heap->arr[7] != NULL);
	assert(*(int*)min_heap->arr[1] == val6);
	assert(*(int*)min_heap->arr[2] == val5);
	assert(*(int*)min_heap->arr[3] == val7);
	assert(*(int*)min_heap->arr[4] == val4);
	assert(*(int*)min_heap->arr[5] == val2);
	assert(*(int*)min_heap->arr[6] == val1);
	assert(*(int*)min_heap->arr[7] == val3);

	addItemToMinHeap(min_heap, (void*)&val8);
	assert(min_heap->index == 7);
	assert(*(int*)min_heap->arr[1] == val6);
	assert(*(int*)min_heap->arr[2] == val5);
	assert(*(int*)min_heap->arr[3] == val7);
	assert(*(int*)min_heap->arr[4] == val4);
	assert(*(int*)min_heap->arr[5] == val2);
	assert(*(int*)min_heap->arr[6] == val1);
	assert(*(int*)min_heap->arr[7] == val3);

	freeMinHeapMemory(min_heap);
	free(min_heap);

	printf("\n");
}

// test getMinHeapRoot() function
void testGetMinHeapRoot() {
	printf("test getMinHeapRoot() function.\n");

	int val1 = 1, val2 = 2, val3 = -1;
	int val4 = 5, val5 = 0, val6 = -5;
	int val7 = 7, val8 = -20;

	void* value;

	int size = 15;

	MinHeap* min_heap = NULL;

	min_heap = createEmptyMinHeap(size, compareIntegers);

	value = getMinHeapRoot(min_heap);
	assert(value == NULL);

	addItemToMinHeap(min_heap, (void*)&val1);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	addItemToMinHeap(min_heap, (void*)&val2);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	addItemToMinHeap(min_heap, (void*)&val3);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	addItemToMinHeap(min_heap, (void*)&val5);
	addItemToMinHeap(min_heap, (void*)&val4);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	addItemToMinHeap(min_heap, (void*)&val6);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val6);

	addItemToMinHeap(min_heap, (void*)&val7);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val6);

	addItemToMinHeap(min_heap, (void*)&val8);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val8);

	assert(min_heap->index == 8);
	assert(*(int*)min_heap->arr[1] == val8);
	assert(*(int*)min_heap->arr[2] == val6);
	assert(*(int*)min_heap->arr[3] == val3);
	assert(*(int*)min_heap->arr[4] == val5);
	assert(*(int*)min_heap->arr[5] == val4);
	assert(*(int*)min_heap->arr[6] == val1);
	assert(*(int*)min_heap->arr[7] == val7);
	assert(*(int*)min_heap->arr[8] == val2);

	freeMinHeapMemory(min_heap);
	free(min_heap);

	printf("\n");
}

// test removeMinHeapRoot() function
void testRemoveMinHeapRoot() {
	// TODO
	printf("test removeMinHeapRoot() function.\n");

	int val1 = 1, val2 = 2, val3 = -1;
	int val4 = 5, val5 = 0, val6 = 15;
	int val7 = 7, val8 = 20;

	void* value;

	int size = 15;

	MinHeap* min_heap = NULL;

	min_heap = createEmptyMinHeap(size, compareIntegers);

	value = removeMinHeapRoot(min_heap);
	assert(value == NULL);

	addItemToMinHeap(min_heap, (void*)&val1);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	value = getMinHeapRoot(min_heap);
	assert(value == NULL);

	addItemToMinHeap(min_heap, (void*)&val2);
	addItemToMinHeap(min_heap, (void*)&val3);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	addItemToMinHeap(min_heap, (void*)&val4);
	addItemToMinHeap(min_heap, (void*)&val5);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val5);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val5);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	addItemToMinHeap(min_heap, (void*)&val1);
	addItemToMinHeap(min_heap, (void*)&val7);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val4);
	assert(min_heap->index == 2);
	assert(*(int*)min_heap->arr[1] == val4);
	assert(*(int*)min_heap->arr[2] == val7);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val4);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);
	assert(min_heap->index == 1);
	assert(*(int*)min_heap->arr[1] == val7);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);

	value = getMinHeapRoot(min_heap);
	assert(value == NULL);
	assert(min_heap->index == 0);

	addItemToMinHeap(min_heap, (void*)&val1);
	addItemToMinHeap(min_heap, (void*)&val5);
	addItemToMinHeap(min_heap, (void*)&val2);
	addItemToMinHeap(min_heap, (void*)&val6);
	addItemToMinHeap(min_heap, (void*)&val7);
	addItemToMinHeap(min_heap, (void*)&val8);
	assert(min_heap->index == 6);
	assert(*(int*)min_heap->arr[1] == val5);
	assert(*(int*)min_heap->arr[2] == val1);
	assert(*(int*)min_heap->arr[3] == val2);
	assert(*(int*)min_heap->arr[4] == val6);
	assert(*(int*)min_heap->arr[5] == val7);
	assert(*(int*)min_heap->arr[6] == val8);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val5);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val5);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	assert(min_heap->index == 5);
	assert(*(int*)min_heap->arr[1] == val1);
	assert(*(int*)min_heap->arr[2] == val7);
	assert(*(int*)min_heap->arr[3] == val2);
	assert(*(int*)min_heap->arr[4] == val6);
	assert(*(int*)min_heap->arr[5] == val8);

	addItemToMinHeap(min_heap, (void*)&val3);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	assert(min_heap->index == 6);
	assert(*(int*)min_heap->arr[1] == val3);
	assert(*(int*)min_heap->arr[2] == val7);
	assert(*(int*)min_heap->arr[3] == val1);
	assert(*(int*)min_heap->arr[4] == val6);
	assert(*(int*)min_heap->arr[5] == val8);
	assert(*(int*)min_heap->arr[6] == val2);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	assert(min_heap->index == 5);
	assert(*(int*)min_heap->arr[1] == val1);
	assert(*(int*)min_heap->arr[2] == val7);
	assert(*(int*)min_heap->arr[3] == val2);
	assert(*(int*)min_heap->arr[4] == val6);
	assert(*(int*)min_heap->arr[5] == val8);

	addItemToMinHeap(min_heap, (void*)&val2);
	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	assert(min_heap->index == 6);
	assert(*(int*)min_heap->arr[1] == val1);
	assert(*(int*)min_heap->arr[2] == val7);
	assert(*(int*)min_heap->arr[3] == val2);
	assert(*(int*)min_heap->arr[4] == val6);
	assert(*(int*)min_heap->arr[5] == val8);
	assert(*(int*)min_heap->arr[6] == val2);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	assert(min_heap->index == 5);
	assert(*(int*)min_heap->arr[1] == val2);
	assert(*(int*)min_heap->arr[2] == val7);
	assert(*(int*)min_heap->arr[3] == val2);
	assert(*(int*)min_heap->arr[4] == val6);
	assert(*(int*)min_heap->arr[5] == val8);

	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	assert(min_heap->index == 4);
	assert(*(int*)min_heap->arr[1] == val2);
	assert(*(int*)min_heap->arr[2] == val7);
	assert(*(int*)min_heap->arr[3] == val8);
	assert(*(int*)min_heap->arr[4] == val6);

	//
	value = removeMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	value = getMinHeapRoot(min_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);

	assert(min_heap->index == 3);
	assert(*(int*)min_heap->arr[1] == val7);
	assert(*(int*)min_heap->arr[2] == val6);
	assert(*(int*)min_heap->arr[3] == val8);

	freeMinHeapMemory(min_heap);
	free(min_heap);

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testCreateEmptyMinHeap();

	testAddItemToMinHeap();

	testGetMinHeapRoot();

	testRemoveMinHeapRoot();

	return 0;
}