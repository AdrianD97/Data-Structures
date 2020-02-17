#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

#include "utils/utils.h"

// create an empty linked list (the method is a kind of C++ constructor)
LinkedList* createEmptyLinkedList() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = list->tail = NULL;
	list->length = 0;

	return list;
}

// add an item in the list
void addItemToLinkedList(LinkedList* list, const char* value) {
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->value, value);
	node->next = NULL;

	if (list->length == 0) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}

	++list->length;
}

// find an item by value
Node* findElementByValue(const LinkedList* list, const char* value) {
	if (list->length == 0) {
		return NULL;
	}

	Node* node = list->head;

	while (node != NULL) {
		if (strcmp(node->value, value) == 0) {
			return node;
		}

		node = node->next;
	}

	return NULL;
}

// remove an item from list(if exists)
void removeItemFromLinkedList(LinkedList* list, const char* value) {
	// empty list
	if (list->length == 0) {
		return;
	}

	// a single item
	if (list->length == 1) {
		if (strcmp(list->head->value, value) == 0) {
			list->length = 0;
			free(list->head);
			list->head = list->tail = NULL;
		}
		return;
	}

	Node* node = list->head;
	// head node has to be removed
	if (strcmp(node->value, value) == 0) {
		list->head = list->head->next;
		--list->length;
		free(node);
		return;
	}

	// remove an ordinary node
	Node* helpNode = list->head;
	node = node->next;

	while (node != NULL) {
		if (strcmp(node->value, value) == 0) {
			break;
		}

		node = node->next;
		helpNode = helpNode->next;
	}

	if (node) {
		helpNode->next = node->next;
		if (node == list->tail) {
			list->tail = helpNode;
		}
		free(node);
		--list->length;
	}
}

// free memory used
void freeLinkedListMemory(LinkedList* list) {
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

// print list items
void displayLinkedList(const LinkedList* list) {
	Node* node = list->head;

	while (node != NULL) {
		printf("%s\n", node->value);

		node = node->next;
	}
	printf("\n");
}

#endif // LINKED_LIST_H