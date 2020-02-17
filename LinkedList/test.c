#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "LinkedList.h"

// Test Node structure
void testNodeStructure() {
	printf("test Node structure.\n");

	char* var = "www.facebook.com";

	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->value, var);
	node->next = NULL;

	assert(strcmp(node->value, var) == 0);
	assert(node->next == NULL);
	free(node);

	printf("\n");
}

// test createEmptyLinkedList() function
void testCreateEmptyLinkedList() {
	printf("test createEmptyLinkedList() function.\n");

	LinkedList* list = NULL;

	list = createEmptyLinkedList();
	
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);

	freeLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test addItemToLinkedList() function
void testAddItemToLinkedList() {
	printf("test addItemToLinkedList() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	LinkedList* list = NULL;

	list = createEmptyLinkedList();

	addItemToLinkedList(list, elem1);
	assert(list->length == 1);
	assert(list->head == list->tail);
	assert(list->head->next == NULL);

	addItemToLinkedList(list, elem2);
	addItemToLinkedList(list, elem3);
	assert(list->length == 3);
	assert(list->head != NULL);
	assert(list->tail != NULL);
	displayLinkedList(list);

	addItemToLinkedList(list, elem4);
	assert(list->length == 4);
	displayLinkedList(list);

	freeLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test findElementByValue() function
void testFindElementByValue() {
	printf("test findElementByValue() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	LinkedList* list = NULL;
	Node* node;

	list = createEmptyLinkedList();

	node = findElementByValue(list, elem1);
	assert(node == NULL);

	addItemToLinkedList(list, elem1);
	addItemToLinkedList(list, elem2);
	addItemToLinkedList(list, elem3);

	node = findElementByValue(list, elem4);
	assert(node == NULL);

	addItemToLinkedList(list, elem4);
	node = findElementByValue(list, elem1);
	assert((node != NULL) && strcmp(list->head->value, elem1) == 0);

	node = findElementByValue(list, elem2);
	assert(node != NULL);

	node = findElementByValue(list, elem3);
	assert(node != NULL);

	node = findElementByValue(list, elem4);
	assert((node != NULL) && strcmp(list->tail->value, elem4) == 0);

	freeLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test removeItemFromLinkedList() function
void testRemoveItemFromLinkedList() {
	printf("test removeItemFromLinkedList() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	LinkedList* list = NULL;

	list = createEmptyLinkedList();
	removeItemFromLinkedList(list, elem1);
	assert(list->length == 0);

	addItemToLinkedList(list, elem1);
	assert(list->length == 1);
	removeItemFromLinkedList(list, elem1);
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);

	addItemToLinkedList(list, elem1);
	addItemToLinkedList(list, elem2);
	addItemToLinkedList(list, elem3);
	assert(list->length == 3);
	displayLinkedList(list);

	removeItemFromLinkedList(list, elem4);
	assert(list->length == 3);
	removeItemFromLinkedList(list, elem1);
	assert(list->length == 2);
	displayLinkedList(list);

	addItemToLinkedList(list, elem1);
	addItemToLinkedList(list, elem4);
	assert(list->length == 4);
	displayLinkedList(list);
	removeItemFromLinkedList(list, elem1);
	assert(list->length == 3);
	removeItemFromLinkedList(list, elem4);
	assert(list->length == 2);
	displayLinkedList(list);

	freeLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testNodeStructure();

	testCreateEmptyLinkedList();

	testAddItemToLinkedList();

	testFindElementByValue();

	testRemoveItemFromLinkedList();

	return 0;
}