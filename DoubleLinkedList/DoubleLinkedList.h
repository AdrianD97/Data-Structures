#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

#include "utils/utils.h"

// create an empty double linked list (the method is a kind of C++ constructor)
DoubleLinkedList* createEmptyDoubleLinkedList() {
	DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));

	list->head = list->tail = NULL;
	list->length = 0;

	return list;
}

// add an item in the list
void addItemToDoubleLinkedList(DoubleLinkedList* list, void* value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;

	if (list->length == 0) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}

	++list->length;
}

// find an element by value
Node* findElementByValue(const DoubleLinkedList* list, const void* value) {
	if (list->length == 0) {
		return NULL;
	}

	int var = list->length;

	Node* node1 = list->head;
	Node* node2 = list->tail;

	while (var > 0) {
		if (node1->value == value) {
			return node1;
		}

		if (node2->value == value) {
			return node2;
		}

		node1 = node1->next;
		node2 = node2->prev;

		var -= 2;
	}

	return NULL;
}

// remove an item from list(if exists)
void removeItemFromDoubleLinkedList(DoubleLinkedList* list, const void* value) {
	Node* node = findElementByValue(list, value);

	if (!node) {
		return;
	}

	// a single item
	if (list->length == 1) {
		list->length = 0;
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}

	// head node has to be removed
	if (node == list->head) {
		list->head = list->head->next;
		list->head->prev = NULL;
		--list->length;
		free(node);
		return;
	}

	// remove an ordinary node
	node->prev->next = node->next;
	if (node == list->tail) {
		list->tail = node->prev;
	} else {
		node->next->prev = node->prev;
	}

	free(node);
	--list->length;
}

// free memory used
void freeDoubleLinkedListMemory(DoubleLinkedList* list) {
	if (list->length == 0) {
		return;
	}

	Node* node = list->head;
	Node* helpNode = list->head;
	node = node->next;

	while (node != NULL) {
		free(helpNode);
		helpNode = node;
		node = node->next;
	}

	free(helpNode);
}

#endif // DOUBLE_LINKED_LIST_H