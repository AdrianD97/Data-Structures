#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "HashTable.h"
#include "hash_functions/hash_functions.h"
#include "../compare_functions/compare_functions.h"
#include "../utils_structures/utils_structures.h"

// test createEmptyHashTable() function
void testCreateEmptyHashTable() {
	printf("test createEmptyHashTable() function\n");

	int size = 200;

	HashTable* hashTable = createEmptyHashTable(size, stringHash, comparePairsWithIntegerKey);
	assert(hashTable->size == size);
	assert(hashTable->hash == stringHash);
	assert(hashTable->map != NULL);
	assert(hashTable->map[0] != NULL);
	assert(hashTable->map[size - 1] != NULL);
	assert(hashTable->map[0]->length == 0);
	assert(hashTable->map[size - 1]->length == 0);

	freeHashTableMemory(hashTable);
	free(hashTable);
	hashTable = NULL;

	printf("\n");
}

// test put() function
void testPut() {
	printf("test put() function.\n");

	// test with keys of string type
	char key1[50], key2[50], key3[50];
	int val1 = 10, val2 = 20, val3 = 30;
	int index;
	Pair* pair;

	strcpy(key1, "www.facebook.com");
	strcpy(key2, "studenti.pub.ro");
	strcpy(key3, "www.geeksforgeeks.org");

	int size = 200;

	HashTable* hashTable = createEmptyHashTable(size, stringHash, comparePairsWithStringKey);
	assert(hashTable->size == size);
	assert(hashTable->hash == stringHash);
	assert(hashTable->map != NULL);
	assert(hashTable->map[0] != NULL);
	assert(hashTable->map[size - 1] != NULL);

	put(hashTable, (void*)key1, (void*)&val1);
	index = stringHash((void*)key1) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);
	
	pair = (Pair*)hashTable->map[index]->head->value;
	assert(strcmp((char*)pair->key, key1) == 0);
	assert(*(int*)pair->value == val1);
	assert(comparePairsWithStringKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(strcmp((char*)pair->key, key1) == 0);
	assert(*(int*)pair->value == val1);

	put(hashTable, (void*)key1, (void*)&val3);
	index = stringHash((void*)key1) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);
	
	pair = (Pair*)hashTable->map[index]->head->value;
	assert(strcmp((char*)pair->key, key1) == 0);
	assert(*(int*)pair->value == val3);
	assert(comparePairsWithStringKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);

	put(hashTable, (void*)key2, (void*)&val2);
	index = stringHash((void*)key2) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(strcmp((char*)pair->key, key2) == 0);
	assert(*(int*)pair->value == val2);
	assert(comparePairsWithStringKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(strcmp((char*)pair->key, key2) == 0);
	assert(*(int*)pair->value == val2);

	put(hashTable, (void*)key3, (void*)&val1);
	index = stringHash((void*)key3) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(strcmp((char*)pair->key, key3) == 0);
	assert(*(int*)pair->value == val1);
	assert(comparePairsWithStringKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(strcmp((char*)pair->key, key3) == 0);
	assert(*(int*)pair->value == val1);

	put(hashTable, (void*)key3, (void*)&val3);
	index = stringHash((void*)key3) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(strcmp((char*)pair->key, key3) == 0);
	assert(*(int*)pair->value == val3);
	assert(comparePairsWithStringKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(strcmp((char*)pair->key, key3) == 0);
	assert(*(int*)pair->value == val3);

	freeHashTableMemory(hashTable);
	free(hashTable);
	hashTable = NULL;

	// test with keys of integer type
	size = 250;
	int key_int1 = 5, key_int2 = 40, key_int3 = 255, key_int4 = 505, key_int5 = 10;

	char val_ch1[50], val_ch2[50], val_ch3[50];

	strcpy(val_ch1, "www.facebook.com");
	strcpy(val_ch2, "studenti.pub.ro");
	strcpy(val_ch3, "www.geeksforgeeks.org");

	hashTable = createEmptyHashTable(size, intHash, comparePairsWithIntegerKey);
	assert(hashTable->size == size);
	assert(hashTable->hash == intHash);
	assert(hashTable->map != NULL);
	assert(hashTable->map[0] != NULL);
	assert(hashTable->map[size - 1] != NULL);

	put(hashTable, (void*)&key_int1, (void*)val_ch1);
	index = intHash((void*)&key_int1) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(*(int*)pair->key == key_int1);
	assert(strcmp((char*)pair->value, val_ch1) == 0);
	assert(comparePairsWithIntegerKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(*(int*)pair->key == key_int1);
	assert(strcmp((char*)pair->value, val_ch1) == 0);

	put(hashTable, (void*)&key_int2, (void*)val_ch2);
	index = intHash((void*)&key_int2) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(*(int*)pair->key == key_int2);
	assert(strcmp((char*)pair->value, val_ch2) == 0);
	assert(comparePairsWithIntegerKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(*(int*)pair->key == key_int2);
	assert(strcmp((char*)pair->value, val_ch2) == 0);

	put(hashTable, (void*)&key_int3, (void*)val_ch3);
	index = intHash((void*)&key_int3) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 2);
	assert(hashTable->map[index]->head != hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->next == hashTable->map[index]->tail);
	assert(hashTable->map[index]->tail->prev == hashTable->map[index]->head);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(*(int*)pair->key == key_int1);
	assert(strcmp((char*)pair->value, val_ch1) == 0);
	assert(comparePairsWithIntegerKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 0);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(*(int*)pair->key == key_int3);
	assert(strcmp((char*)pair->value, val_ch3) == 0);

	put(hashTable, (void*)&key_int4, (void*)val_ch2);
	index = intHash((void*)&key_int4) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 3);
	assert(hashTable->map[index]->head != hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->next->next == hashTable->map[index]->tail);
	assert(hashTable->map[index]->tail->prev->prev == hashTable->map[index]->head);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(*(int*)pair->key == key_int1);
	assert(strcmp((char*)pair->value, val_ch1) == 0);
	assert(comparePairsWithIntegerKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 0);
	assert(comparePairsWithIntegerKey(hashTable->map[index]->head->next->value, hashTable->map[index]->tail->prev->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(*(int*)pair->key == key_int4);
	assert(strcmp((char*)pair->value, val_ch2) == 0);

	put(hashTable, (void*)&key_int5, (void*)val_ch3);
	index = intHash((void*)&key_int5) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 1);
	assert(hashTable->map[index]->head == hashTable->map[index]->tail);
	assert(hashTable->map[index]->head->prev == NULL);
	assert(hashTable->map[index]->tail->next == NULL);

	pair = (Pair*)hashTable->map[index]->head->value;
	assert(*(int*)pair->key == key_int5);
	assert(strcmp((char*)pair->value, val_ch3) == 0);
	assert(comparePairsWithIntegerKey(hashTable->map[index]->head->value, hashTable->map[index]->tail->value) == 1);
	pair = (Pair*)hashTable->map[index]->tail->value;
	assert(*(int*)pair->key == key_int5);
	assert(strcmp((char*)pair->value, val_ch3) == 0);

	freeHashTableMemory(hashTable);
	free(hashTable);
	hashTable = NULL;

	printf("\n");
}

// test get() function
void testGet() {
	printf("test get() function.\n");

	// test with keys of string type
	char key1[50], key2[50], key3[50], key4[50];
	int val1 = 10, val2 = 20, val3 = 30;
	int index;

	strcpy(key1, "www.facebook.com");
	strcpy(key2, "studenti.pub.ro");
	strcpy(key3, "www.geeksforgeeks.org");
	strcpy(key4, "www.linkedin.com");

	int size = 200;

	HashTable* hashTable = createEmptyHashTable(size, stringHash, comparePairsWithStringKey);
	void* value;

	value = get(hashTable, (void*)key1);
	assert(value == NULL);
	value = get(hashTable, (void*)key2);
	assert(value == NULL);

	put(hashTable, (void*)key1, (void*)&val2);
	value = get(hashTable, (void*)key2);
	assert(value == NULL);

	value = get(hashTable, (void*)key1);
	assert(value != NULL);
	assert(*(int*)value == val2);

	put(hashTable, (void*)key1, (void*)&val1);
	value = get(hashTable, (void*)key2);
	assert(value == NULL);

	value = get(hashTable, (void*)key1);
	assert(value != NULL);
	assert(*(int*)value == val1);

	put(hashTable, (void*)key2, (void*)&val3);
	value = get(hashTable, (void*)key3);
	assert(value == NULL);

	value = get(hashTable, (void*)key2);
	assert(value != NULL);
	assert(*(int*)value == val3);

	put(hashTable, (void*)key3, (void*)&val3);
	value = get(hashTable, (void*)key3);
	assert(value != NULL);
	assert(*(int*)value == val3);

	put(hashTable, (void*)key3, (void*)&val1);
	value = get(hashTable, (void*)key3);
	assert(value != NULL);
	assert(*(int*)value == val1);

	freeHashTableMemory(hashTable);
	free(hashTable);
	hashTable = NULL;

	// test with keys of integer type
	size = 250;
	int key_int1 = 5, key_int2 = 40, key_int3 = 255, key_int4 = 505, key_int5 = 10;

	char val_ch1[50], val_ch2[50], val_ch3[50];

	strcpy(val_ch1, "www.facebook.com");
	strcpy(val_ch2, "studenti.pub.ro");
	strcpy(val_ch3, "www.geeksforgeeks.org");

	hashTable = createEmptyHashTable(size, intHash, comparePairsWithIntegerKey);

	value = get(hashTable, (void*)&key_int1);
	assert(value == NULL);
	value = get(hashTable, (void*)&key_int5);
	assert(value == NULL);

	put(hashTable, (void*)&key_int1, (void*)val_ch1);
	value = get(hashTable, (void*)&key_int5);
	assert(value == NULL);
	
	value = get(hashTable, (void*)&key_int1);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch1) == 0);

	put(hashTable, (void*)&key_int1, (void*)val_ch3);
	value = get(hashTable, (void*)&key_int1);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch3) == 0);

	put(hashTable, (void*)&key_int3, (void*)val_ch2);
	put(hashTable, (void*)&key_int4, (void*)val_ch1);
	value = get(hashTable, (void*)&key_int1);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch3) == 0);
	value = get(hashTable, (void*)&key_int3);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch2) == 0);
	value = get(hashTable, (void*)&key_int4);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch1) == 0);

	put(hashTable, (void*)&key_int2, (void*)val_ch2);
	put(hashTable, (void*)&key_int5, (void*)val_ch1);
	value = get(hashTable, (void*)&key_int2);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch2) == 0);
	value = get(hashTable, (void*)&key_int5);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch1) == 0);

	freeHashTableMemory(hashTable);
	free(hashTable);
	hashTable = NULL;

	printf("\n");
}

// test erase() function
void testErase() {
	printf("test erase() function.\n");

	// test with keys of string type
	char key1[50], key2[50], key3[50], key4[50];
	int val1 = 10, val2 = 20, val3 = 30;
	int index;

	strcpy(key1, "www.facebook.com");
	strcpy(key2, "studenti.pub.ro");
	strcpy(key3, "www.geeksforgeeks.org");
	strcpy(key4, "www.linkedin.com");

	int size = 200;
	void* value;

	HashTable* hashTable = createEmptyHashTable(size, stringHash, comparePairsWithStringKey);

	erase(hashTable, (void*)key1);
	index = stringHash((void*)key1) % hashTable->size;
	assert(hashTable->map[index] != NULL);

	put(hashTable, (void*)key1, (void*)&val1);
	put(hashTable, (void*)key1, (void*)&val2);

	value = get(hashTable, (void*)key1);
	assert(*(int*)value == val2);

	erase(hashTable, (void*)key1);
	index = stringHash((void*)key1) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 0);
	value = get(hashTable, (void*)key1);
	assert(value == NULL);

	erase(hashTable, (void*)key1);
	index = stringHash((void*)key1) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 0);

	put(hashTable, (void*)key1, (void*)&val1);
	put(hashTable, (void*)key2, (void*)&val3);
	put(hashTable, (void*)key3, (void*)&val2);

	value = get(hashTable, (void*)key1);
	assert(value != NULL);
	assert(*(int*)value == val1);
	index = stringHash((void*)key1) % hashTable->size;
	assert(hashTable->map[index]->length == 1);

	value = get(hashTable, (void*)key2);
	assert(value != NULL);
	assert(*(int*)value == val3);
	index = stringHash((void*)key2) % hashTable->size;
	assert(hashTable->map[index]->length == 1);

	erase(hashTable, (void*)key2);
	index = stringHash((void*)key2) % hashTable->size;
	assert(hashTable->map[index] != NULL);
	assert(hashTable->map[index]->length == 0);

	value = get(hashTable, (void*)key3);
	assert(value != NULL);
	assert(*(int*)value == val2);
	index = stringHash((void*)key3) % hashTable->size;
	assert(hashTable->map[index]->length == 1);

	value = get(hashTable, (void*)key2);
	assert(value == NULL);

	freeHashTableMemory(hashTable);
	free(hashTable);
	hashTable = NULL;

	// test with keys of integer type
	size = 250;
	int key_int1 = 5, key_int2 = 40, key_int3 = 255, key_int4 = 505, key_int5 = 10;

	char val_ch1[50], val_ch2[50], val_ch3[50];

	strcpy(val_ch1, "www.facebook.com");
	strcpy(val_ch2, "studenti.pub.ro");
	strcpy(val_ch3, "www.geeksforgeeks.org");

	hashTable = createEmptyHashTable(size, intHash, comparePairsWithIntegerKey);

	put(hashTable, (void*)&key_int1, (void*)val_ch1);
	put(hashTable, (void*)&key_int2, (void*)val_ch2);
	put(hashTable, (void*)&key_int3, (void*)val_ch3);

	value = get(hashTable, (void*)&key_int1);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch1) == 0);

	value = get(hashTable, (void*)&key_int3);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch3) == 0);

	index = intHash((void*)&key_int1) % hashTable->size;
	assert(hashTable->map[index]->length == 2);
	index = intHash((void*)&key_int3) % hashTable->size;
	assert(hashTable->map[index]->length == 2);

	index = intHash((void*)&key_int2) % hashTable->size;
	assert(hashTable->map[index]->length == 1);

	put(hashTable, (void*)&key_int4, (void*)val_ch2);
	value = get(hashTable, (void*)&key_int4);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch2) == 0);

	index = intHash((void*)&key_int1) % hashTable->size;
	assert(hashTable->map[index]->length == 3);
	index = intHash((void*)&key_int4) % hashTable->size;
	assert(hashTable->map[index]->length == 3);

	erase(hashTable, (void*)&key_int3);
	value = get(hashTable, (void*)&key_int3);
	assert(value == NULL);

	index = intHash((void*)&key_int1) % hashTable->size;
	assert(hashTable->map[index]->length == 2);
	index = intHash((void*)&key_int4) % hashTable->size;
	assert(hashTable->map[index]->length == 2);

	erase(hashTable, (void*)&key_int1);
	value = get(hashTable, (void*)&key_int1);
	assert(value == NULL);
	index = intHash((void*)&key_int4) % hashTable->size;
	assert(hashTable->map[index]->length == 1);

	erase(hashTable, (void*)&key_int2);
	value = get(hashTable, (void*)&key_int2);
	assert(value == NULL);
	index = intHash((void*)&key_int2) % hashTable->size;
	assert(hashTable->map[index]->length == 0);

	put(hashTable, (void*)&key_int1, (void*)val_ch3);
	value = get(hashTable, (void*)&key_int1);
	assert(value != NULL);
	assert(strcmp((char*)value, val_ch3) == 0);

	erase(hashTable, (void*)&key_int1);
	value = get(hashTable, (void*)&key_int1);
	assert(value == NULL);

	freeHashTableMemory(hashTable);
	free(hashTable);
	hashTable = NULL;

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testCreateEmptyHashTable();

	testPut();

	testGet();

	testErase();

	return 0;
}