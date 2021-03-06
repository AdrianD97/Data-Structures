#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "LinkedList.h"

// test Node structure
void testNodeStructure() {
	printf("test Node structure.\n");

	char* var = "www.facebook.com";

	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->value, var);
	node->next = NULL;

	assert(strcmp(node->value, var) == 0);
	assert(node->next == NULL);
	free(node);
	node = NULL;

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
	assert(strcmp(list->head->value, elem1) == 0);
	assert(list->head->next == NULL);

	addItemToLinkedList(list, elem2);
	addItemToLinkedList(list, elem3);
	assert(list->length == 3);
	assert(strcmp(list->head->next->value, elem2) == 0);
	assert(strcmp(list->head->next->next->value, elem3) == 0);
	assert(strcmp(list->tail->value, elem3) == 0);

	displayLinkedList(list);

	addItemToLinkedList(list, elem4);
	assert(list->length == 4);
	assert(list->head->next->next->next == list->tail);
	assert(strcmp(list->head->next->next->next->value, elem4) == 0);
	assert(strcmp(list->tail->value, elem4) == 0);
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
	assert((node != NULL) && strcmp(node->value, elem1) == 0);
	assert(node == list->head);

	node = findElementByValue(list, elem2);
	assert(node != NULL);

	node = findElementByValue(list, elem3);
	assert(node != NULL);

	node = findElementByValue(list, elem4);
	assert((node != NULL) && strcmp(node->value, elem4) == 0);
	assert(node == list->tail);

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
	Node* node;

	list = createEmptyLinkedList();
	node = removeItemFromLinkedList(list, elem1);
	assert(node == NULL);
	assert(list->length == 0);

	addItemToLinkedList(list, elem1);
	assert(list->length == 1);
	assert(list->head == list->tail);
	assert(strcmp(list->head->value, elem1) == 0);
	assert(strcmp(list->tail->value, elem1) == 0);

	node = removeItemFromLinkedList(list, elem4);
	assert(node == NULL);
	assert(list->length == 1);
	assert(list->head == list->tail);
	assert(strcmp(list->head->value, elem1) == 0);
	assert(strcmp(list->tail->value, elem1) == 0);

	node = removeItemFromLinkedList(list, elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem1) == 0);
	free(node);
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);

	addItemToLinkedList(list, elem1);
	addItemToLinkedList(list, elem2);
	addItemToLinkedList(list, elem3);
	assert(list->length == 3);
	assert(strcmp(list->head->value, elem1) == 0);
	assert(strcmp(list->head->next->value, elem2) == 0);
	assert(strcmp(list->head->next->next->value, elem3) == 0);
	assert(strcmp(list->tail->value, elem3) == 0);
	displayLinkedList(list);

	node = removeItemFromLinkedList(list, elem4);
	assert(node == NULL);
	assert(list->length == 3);
	assert(list->head->next->next == list->tail);
	assert(strcmp(list->tail->value, elem3) == 0);

	node = removeItemFromLinkedList(list, elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem1) == 0);
	free(node);
	assert(list->length == 2);
	assert(strcmp(list->head->value, elem2) == 0);
	assert(strcmp(list->head->next->value, elem3) == 0);
	assert(list->head->next->next == NULL);
	assert(strcmp(list->tail->value, elem3) == 0);
	displayLinkedList(list);

	addItemToLinkedList(list, elem1);
	addItemToLinkedList(list, elem4);
	assert(list->length == 4);
	assert(strcmp(list->head->value, elem2) == 0);
	assert(strcmp(list->head->next->value, elem3) == 0);
	assert(strcmp(list->head->next->next->value, elem1) == 0);
	assert(strcmp(list->head->next->next->next->value, elem4) == 0);
	assert(strcmp(list->tail->value, elem4) == 0);
	displayLinkedList(list);

	node = removeItemFromLinkedList(list, elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem1) == 0);
	free(node);
	assert(list->length == 3);
	assert(strcmp(list->head->value, elem2) == 0);
	assert(strcmp(list->head->next->value, elem3) == 0);
	assert(strcmp(list->head->next->next->value, elem4) == 0);
	assert(list->head->next->next == list->tail);
	assert(strcmp(list->tail->value, elem4) == 0);

	node = removeItemFromLinkedList(list, elem4);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem4) == 0);
	free(node);
	assert(list->length == 2);
	assert(strcmp(list->head->value, elem2) == 0);
	assert(strcmp(list->head->next->value, elem3) == 0);
	assert(list->head->next->next == NULL);
	assert(strcmp(list->tail->value, elem3) == 0);
	displayLinkedList(list);

	freeLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test al LinkedList methods
void testAllMethods() {
	printf("test all methods.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50], elem5[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");
	strcpy(elem5, "www.linkedin.com");

	LinkedList* list = NULL;
	Node* node;

	list = createEmptyLinkedList();
	assert(list->length == 0);

	addItemToLinkedList(list, elem1);
	addItemToLinkedList(list, elem2);
	addItemToLinkedList(list, elem3);
	assert(list->length == 3);

	node = findElementByValue(list, elem1);
	assert((node != NULL) && strcmp(node->value, elem1) == 0);
	assert(node == list->head);

	node = findElementByValue(list, elem2);
	assert((node != NULL) && strcmp(node->value, elem2) == 0);
	assert(node == list->head->next);

	node = removeItemFromLinkedList(list, elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem1) == 0);
	free(node);
	node = findElementByValue(list, elem1);
	assert(node == NULL);
	assert(strcmp(list->head->value, elem2) == 0);
	assert(strcmp(list->tail->value, elem3) == 0);

	addItemToLinkedList(list, elem4);
	addItemToLinkedList(list, elem5);
	node = findElementByValue(list, elem4);
	assert((node != NULL) && strcmp(node->value, elem4) == 0);
	assert(strcmp(node->next->value, elem5) == 0);
	assert(node->next == list->tail);

	node = removeItemFromLinkedList(list, elem3);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem3) == 0);
	free(node);
	assert(strcmp(list->head->value, elem2) == 0);
	assert(strcmp(list->head->next->value, elem4) == 0);
	assert(strcmp(list->head->next->next->value, elem5) == 0);
	assert(strcmp(list->tail->value, elem5) == 0);

	addItemToLinkedList(list, elem1);
	node = findElementByValue(list, elem5);
	assert((node != NULL) && strcmp(node->value, elem5) == 0);
	assert(node->next == list->tail);
	assert(strcmp(list->tail->value, elem1) == 0);

	node = removeItemFromLinkedList(list, elem2);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem2) == 0);
	free(node);
	assert(list->length == 3);
	assert(strcmp(list->head->value, elem4) == 0);
	assert(strcmp(list->head->next->value, elem5) == 0);

	node = removeItemFromLinkedList(list, elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem1) == 0);
	free(node);
	assert(list->length == 2);
	assert(strcmp(list->head->value, elem4) == 0);
	assert(strcmp(list->head->next->value, elem5) == 0);
	assert(strcmp(list->tail->value, elem5) == 0);

	node = removeItemFromLinkedList(list, elem4);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem4) == 0);
	free(node);
	assert(list->length == 1);
	assert(strcmp(list->head->value, elem5) == 0);
	assert(list->head->next == NULL);
	assert(list->head == list->tail);
	assert(strcmp(list->tail->value, elem5) == 0);

	node = removeItemFromLinkedList(list, elem5);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(strcmp(node->value, elem5) == 0);
	free(node);
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);

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

	testAllMethods();

	return 0;
}