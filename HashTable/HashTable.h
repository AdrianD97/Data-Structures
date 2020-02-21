#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

#include "utils_hash_table/utils_hash_table.h"
#include "../utils_structures/utils_structures.h"

// create an empty hash table (the method is a kind of C++ constructor)
HashTable* createEmptyHashTable(int size, unsigned int (*hash)(void*), unsigned int (*compare)(void*, void*)) {
	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));

	hashTable->size = size;
	hashTable->hash = hash;
	hashTable->map = (DoubleLinkedList**)malloc(size * sizeof(DoubleLinkedList*));

	for (unsigned int i = 0; i < size; ++i) {
		hashTable->map[i] = createEmptyDoubleLinkedList(compare);
	}

	return hashTable;
}

// add an item to hash table
void put(HashTable* hashTable, void* key, void* value) {
	int index = hashTable->hash(key) % hashTable->size;
	Pair* pair = (Pair*)malloc(sizeof(Pair));
	pair->key = key;
	pair->value = value;

	Node* node = findElementByValue(hashTable->map[index], (void*)pair);
	if (node) {
		Pair* help = (Pair*)node->value;
		help->value = value;
		free(pair);
	} else {
	 	addItemToDoubleLinkedList(hashTable->map[index], (void*)pair);
	}
}

// get value associated with the given key
void* get(const HashTable* hashTable, void* key) {
	int index = hashTable->hash(key) % hashTable->size;

	Pair* pair = (Pair*)malloc(sizeof(Pair));
	pair->key = key;
	pair->value = NULL;

	Node* node = findElementByValue(hashTable->map[index], (void*)pair);

	free(pair);
	if (!node) {
		return NULL;
	}

	Pair* pairHelp = (Pair*)node->value;

	return pairHelp->value;
}

// remove a (key, value) pair from hash table
void erase(HashTable* hashTable, void* key) {
	int index = hashTable->hash(key) % hashTable->size;

	Pair* pair = (Pair*)malloc(sizeof(Pair));
	pair->key = key;
	pair->value = NULL;

	Node* node = removeItemFromDoubleLinkedList(hashTable->map[index], (void*)pair);
	if (node) {
		free(node->value);
		free(node);
	}

	free(pair);
}

// free used memory
void freeHashTableMemory(HashTable* hashTable) {
	if (!hashTable) {
		return;
	}
	
	for (unsigned int i = 0; i < hashTable->size; ++i) {
		Node* node = hashTable->map[i]->head;
		while (node != NULL) {
			free(node->value);
			node = node->next;
		}

		freeDoubleLinkedListMemory(hashTable->map[i]);
		free(hashTable->map[i]);
	}

	free(hashTable->map);
	hashTable->map = NULL;
}

#endif // HASH_TABLE_H