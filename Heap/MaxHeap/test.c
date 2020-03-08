#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "MaxHeap.h"
#include "../../compare_functions/compare_functions_.h"

// test createEmptyMaxHeap() function
void testCreateEmptyMaxHeap() {
	printf("test createEmptyMaxHeap() function.\n");

	int size = 100;

	MaxHeap* max_heap = NULL;

	max_heap = createEmptyMaxHeap(size, compareIntegers);

	assert(max_heap != NULL);
	assert(max_heap->size == size);
	assert(max_heap->index == 0);
	assert(max_heap->compare == compareIntegers);
	assert(max_heap->arr != NULL);
	assert(max_heap->arr[0] == NULL);
	assert(max_heap->arr[1] == NULL);
	assert(max_heap->arr[size] == NULL);

	freeMaxHeapMemory(max_heap);
	free(max_heap);

	printf("\n");
}

// test addItemToMaxHeap() function
void tesAddItemToMaxHeap() {
	printf("test addItemToMaxHeap() function.\n");

	int val1 = 1, val2 = 2, val3 = -3, val4 = 4;
	int val5 = 17, val6 = -2, val7 = 13, val8 = 94;
	int val9 = 120;

	int size = 9;

	MaxHeap* max_heap = NULL;

	max_heap = createEmptyMaxHeap(size, compareIntegers);

	addItemToMaxHeap(max_heap, (void*)&val2);
	assert(max_heap->index == 1);
	assert(max_heap->arr[1] != NULL);
	assert(*(int*)max_heap->arr[1] == val2);

	addItemToMaxHeap(max_heap, (void*)&val3);
	assert(max_heap->index == 2);
	assert(*(int*)max_heap->arr[1] == val2);
	assert(*(int*)max_heap->arr[2] == val3);

	addItemToMaxHeap(max_heap, (void*)&val7);
	assert(max_heap->index == 3);
	assert(*(int*)max_heap->arr[1] == val7);
	assert(*(int*)max_heap->arr[2] == val3);
	assert(*(int*)max_heap->arr[3] == val2);

	addItemToMaxHeap(max_heap, (void*)&val1);
	assert(max_heap->index == 4);
	assert(*(int*)max_heap->arr[1] == val7);
	assert(*(int*)max_heap->arr[2] == val1);
	assert(*(int*)max_heap->arr[3] == val2);
	assert(*(int*)max_heap->arr[4] == val3);

	addItemToMaxHeap(max_heap, (void*)&val4);
	assert(max_heap->index == 5);
	assert(*(int*)max_heap->arr[1] == val7);
	assert(*(int*)max_heap->arr[2] == val4);
	assert(*(int*)max_heap->arr[3] == val2);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val1);

	addItemToMaxHeap(max_heap, (void*)&val5);
	assert(max_heap->index == 6);
	assert(*(int*)max_heap->arr[1] == val5);
	assert(*(int*)max_heap->arr[2] == val4);
	assert(*(int*)max_heap->arr[3] == val7);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val2);

	addItemToMaxHeap(max_heap, (void*)&val6);
	assert(max_heap->index == 7);
	assert(*(int*)max_heap->arr[1] == val5);
	assert(*(int*)max_heap->arr[2] == val4);
	assert(*(int*)max_heap->arr[3] == val7);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val2);
	assert(*(int*)max_heap->arr[7] == val6);

	addItemToMaxHeap(max_heap, (void*)&val8);
	assert(max_heap->index == 8);
	assert(*(int*)max_heap->arr[1] == val8);
	assert(*(int*)max_heap->arr[2] == val5);
	assert(*(int*)max_heap->arr[3] == val7);
	assert(*(int*)max_heap->arr[4] == val4);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val2);
	assert(*(int*)max_heap->arr[7] == val6);
	assert(*(int*)max_heap->arr[8] == val3);

	addItemToMaxHeap(max_heap, (void*)&val8);
	assert(max_heap->index == 9);
	assert(*(int*)max_heap->arr[1] == val8);
	assert(*(int*)max_heap->arr[2] == val8);
	assert(*(int*)max_heap->arr[3] == val7);
	assert(*(int*)max_heap->arr[4] == val5);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val2);
	assert(*(int*)max_heap->arr[7] == val6);
	assert(*(int*)max_heap->arr[8] == val3);
	assert(*(int*)max_heap->arr[9] == val4);

	addItemToMaxHeap(max_heap, (void*)&val9);
	assert(max_heap->index == 9);
	assert(*(int*)max_heap->arr[1] == val8);
	assert(*(int*)max_heap->arr[2] == val8);
	assert(*(int*)max_heap->arr[3] == val7);
	assert(*(int*)max_heap->arr[4] == val5);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val2);
	assert(*(int*)max_heap->arr[7] == val6);
	assert(*(int*)max_heap->arr[8] == val3);
	assert(*(int*)max_heap->arr[9] == val4);

	freeMaxHeapMemory(max_heap);
	free(max_heap);

	printf("\n");
}

// test getMaxHeapRoot() function
void tesGetMaxHeapRoot() {
	printf("test getMaxHeapRoot() function.\n");

	int val1 = 1, val2 = 2, val3 = -3, val4 = 4;
	int val5 = 17, val6 = -2, val7 = 13, val8 = 94;
	int val9 = 120;

	void* value;

	int size = 9;

	MaxHeap* max_heap = NULL;

	max_heap = createEmptyMaxHeap(size, compareIntegers);

	value = getMaxHeapRoot(max_heap);
	assert(value == NULL);

	addItemToMaxHeap(max_heap, (void*)&val2);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	addItemToMaxHeap(max_heap, (void*)&val3);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	addItemToMaxHeap(max_heap, (void*)&val7);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);

	addItemToMaxHeap(max_heap, (void*)&val1);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);

	addItemToMaxHeap(max_heap, (void*)&val4);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);

	addItemToMaxHeap(max_heap, (void*)&val5);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val5);

	addItemToMaxHeap(max_heap, (void*)&val6);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val5);

	addItemToMaxHeap(max_heap, (void*)&val8);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val8);

	addItemToMaxHeap(max_heap, (void*)&val8);
	addItemToMaxHeap(max_heap, (void*)&val8);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val8);

	addItemToMaxHeap(max_heap, (void*)&val9);
	addItemToMaxHeap(max_heap, (void*)&val8);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val8);
	
	assert(max_heap->index == 9);
	assert(*(int*)max_heap->arr[1] == val8);
	assert(*(int*)max_heap->arr[2] == val8);
	assert(*(int*)max_heap->arr[3] == val7);
	assert(*(int*)max_heap->arr[4] == val5);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val2);
	assert(*(int*)max_heap->arr[7] == val6);
	assert(*(int*)max_heap->arr[8] == val3);
	assert(*(int*)max_heap->arr[9] == val4);

	freeMaxHeapMemory(max_heap);
	free(max_heap);

	printf("\n");
}

// test removeMaxHeapRoot() funtion
void testRemoveMaxHeapRoot() {
	printf("test removeMaxHeapRoot() funtion.\n");

	int val1 = 1, val2 = 2, val3 = -3, val4 = 4;
	int val5 = 17, val6 = -2, val7 = 13, val8 = 94;
	int val9 = 120;

	void* value;

	int size = 9;

	MaxHeap* max_heap = NULL;

	max_heap = createEmptyMaxHeap(size, compareIntegers);

	value = removeMaxHeapRoot(max_heap);
	assert(value == NULL);

	addItemToMaxHeap(max_heap, (void*)&val3);
	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	value = getMaxHeapRoot(max_heap);
	assert(value == NULL);

	addItemToMaxHeap(max_heap, (void*)&val3);
	addItemToMaxHeap(max_heap, (void*)&val1);
	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val3);

	addItemToMaxHeap(max_heap, (void*)&val1);
	addItemToMaxHeap(max_heap, (void*)&val2);
	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	addItemToMaxHeap(max_heap, (void*)&val6);
	addItemToMaxHeap(max_heap, (void*)&val7);
	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	assert(max_heap->index == 3);
	assert(*(int*)max_heap->arr[1] == val1);
	assert(*(int*)max_heap->arr[2] == val3);
	assert(*(int*)max_heap->arr[3] == val6);

	addItemToMaxHeap(max_heap, (void*)&val4);
	addItemToMaxHeap(max_heap, (void*)&val9);
	addItemToMaxHeap(max_heap, (void*)&val7);
	addItemToMaxHeap(max_heap, (void*)&val8);
	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val9);

	assert(max_heap->index == 7);
	assert(*(int*)max_heap->arr[1] == val9);
	assert(*(int*)max_heap->arr[2] == val4);
	assert(*(int*)max_heap->arr[3] == val8);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val6);
	assert(*(int*)max_heap->arr[7] == val7);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val9);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val8);
	assert(max_heap->index == 6);
	assert(*(int*)max_heap->arr[1] == val8);
	assert(*(int*)max_heap->arr[2] == val4);
	assert(*(int*)max_heap->arr[3] == val7);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val6);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val8);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);
	assert(max_heap->index == 5);
	assert(*(int*)max_heap->arr[1] == val7);
	assert(*(int*)max_heap->arr[2] == val4);
	assert(*(int*)max_heap->arr[3] == val6);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val1);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val7);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val4);
	assert(max_heap->index == 4);
	assert(*(int*)max_heap->arr[1] == val4);
	assert(*(int*)max_heap->arr[2] == val1);
	assert(*(int*)max_heap->arr[3] == val6);
	assert(*(int*)max_heap->arr[4] == val3);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val4);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);
	assert(max_heap->index == 3);
	assert(*(int*)max_heap->arr[1] == val1);
	assert(*(int*)max_heap->arr[2] == val3);
	assert(*(int*)max_heap->arr[3] == val6);

	addItemToMaxHeap(max_heap, (void*)&val4);
	addItemToMaxHeap(max_heap, (void*)&val5);
	addItemToMaxHeap(max_heap, (void*)&val2);
	assert(max_heap->index == 6);
	assert(*(int*)max_heap->arr[1] == val5);
	assert(*(int*)max_heap->arr[2] == val4);
	assert(*(int*)max_heap->arr[3] == val2);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val1);
	assert(*(int*)max_heap->arr[6] == val6);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val5);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val4);
	assert(max_heap->index == 5);
	assert(*(int*)max_heap->arr[1] == val4);
	assert(*(int*)max_heap->arr[2] == val1);
	assert(*(int*)max_heap->arr[3] == val2);
	assert(*(int*)max_heap->arr[4] == val3);
	assert(*(int*)max_heap->arr[5] == val6);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val4);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);
	assert(max_heap->index == 4);
	assert(*(int*)max_heap->arr[1] == val2);
	assert(*(int*)max_heap->arr[2] == val1);
	assert(*(int*)max_heap->arr[3] == val6);
	assert(*(int*)max_heap->arr[4] == val3);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val2);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);
	assert(max_heap->index == 3);
	assert(*(int*)max_heap->arr[1] == val1);
	assert(*(int*)max_heap->arr[2] == val3);
	assert(*(int*)max_heap->arr[3] == val6);

	value = removeMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val1);

	value = getMaxHeapRoot(max_heap);
	assert(value != NULL);
	assert(*(int*)value == val6);
	assert(max_heap->index == 2);
	assert(*(int*)max_heap->arr[1] == val6);
	assert(*(int*)max_heap->arr[2] == val3);

	freeMaxHeapMemory(max_heap);
	free(max_heap);

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testCreateEmptyMaxHeap();

	tesAddItemToMaxHeap();

	tesGetMaxHeapRoot();

	testRemoveMaxHeapRoot();

	return 0;
}