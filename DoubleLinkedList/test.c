#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "DoubleLinkedList.h"
#include "../compare_functions/compare_functions.h"

// Test Node structure
void testNodeStructure() {
	printf("test Node structure.\n");

	// use a string
	char* var = "www.facebook.com";
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->value = (void*)var;
	node1->next = NULL;
	node1->prev = NULL;

	assert(strcmp((char*)node1->value, var) == 0);
	assert(node1->next == NULL);
	assert(node1->prev == NULL);
	free(node1);
	node1 = NULL;

	// use an integer
	int val = 100;
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->value = (void*)&val;
	node2->next = NULL;
	node2->prev = NULL;

	assert(*(int*)node2->value == val);
	assert(node2->next == NULL);
	assert(node2->prev == NULL);
	free(node2);
	node2 = NULL;

	// use a character
	char ch = 'A';
	Node* node3 = (Node*)malloc(sizeof(Node));
	node3->value = (void*)&ch;
	node3->next = NULL;
	node3->prev = NULL;

	assert(*(char*)node3->value == ch);
	assert(node3->next == NULL);
	assert(node3->prev == NULL);
	free(node3);
	node3 = NULL;

	printf("\n");
}

// test createEmptyDoubleLinkedList() function
void testCreateEmptyDoubleLinkedList() {
	printf("test createEmptyDoubleLinkedList() function.\n");

	DoubleLinkedList* list = NULL;

	list = createEmptyDoubleLinkedList(compareStrings);
	
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);
	assert(list->compare == compareStrings);

	freeDoubleLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test addItemToDoubleLinkedList() function
void testAddItemToDoubleLinkedList() {
	printf("test addItemToDoubleLinkedList() function.\n");

	char elem1[50];
	strcpy(elem1, "www.facebook.com");
	DoubleLinkedList* list = NULL;

	list = createEmptyDoubleLinkedList(compareStrings);
	assert(list->compare == compareStrings);

	addItemToDoubleLinkedList(list, (void*)elem1);
	assert(list->length == 1);
	assert(list->head != NULL);
	assert(list->tail != NULL);
	assert(list->head == list->tail);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(strcmp((char*)list->head->value, elem1) == 0);
	assert(strcmp((char*)list->tail->value, elem1) == 0);
	assert(compareStrings(list->head->value, (void*)elem1) == 1);
	assert(compareStrings(list->tail->value, (void*)elem1) == 1);

	freeDoubleLinkedListMemory(list);
	free(list);
	list = NULL;

	char elem2[50], elem3[50], elem4[50], elem5[50];
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	list = createEmptyDoubleLinkedList(compareStrings);
	assert(list->compare == compareStrings);

	addItemToDoubleLinkedList(list, (void*)elem1);
	addItemToDoubleLinkedList(list, (void*)elem2);
	assert(list->length == 2);
	assert(list->head != list->tail);
	assert(list->head->next == list->tail);
	assert(list->tail->prev == list->head);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(strcmp((char*)list->head->value, elem1) == 0);
	assert(strcmp((char*)list->head->next->value, elem2) == 0);
	assert(strcmp((char*)list->tail->value, elem2) == 0);
	assert(strcmp((char*)list->tail->prev->value, elem1) == 0);
	assert(compareStrings(list->head->value, (void*)elem1) == 1);
	assert(compareStrings(list->tail->value, (void*)elem2) == 1);
	assert(compareStrings(list->head->value, list->tail->value) == 0);

	addItemToDoubleLinkedList(list, (void*)elem3);
	addItemToDoubleLinkedList(list, (void*)elem4);
	assert(list->length == 4);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(strcmp((char*)list->head->value, elem1) == 0);
	assert(strcmp((char*)list->tail->value, elem4) == 0);
	assert(strcmp((char*)list->head->next->next->next->value, elem4) == 0);
	assert(strcmp((char*)list->tail->prev->value, elem3) == 0);
	assert(strcmp((char*)list->tail->prev->prev->value, elem2) == 0);
	assert(strcmp((char*)list->tail->prev->prev->prev->value, elem1) == 0);
	assert(strcmp((char*)list->tail->prev->prev->next->value, elem3) == 0);
	assert(strcmp((char*)list->head->next->next->prev->value, elem2) == 0);
	assert(strcmp((char*)list->head->next->next->next->prev->prev->value, elem2) == 0);
	assert(compareStrings(list->head->value, (void*)elem1) == 1);
	assert(compareStrings(list->tail->value, (void*)elem4) == 1);
	assert(compareStrings(list->head->next->value, list->tail->prev->value) == 0);

	strcpy(elem5, "www.linkedin.com");
	addItemToDoubleLinkedList(list, (void*)elem5);
	assert(list->length == 5);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(strcmp((char*)list->head->value, elem1) == 0);
	assert(strcmp((char*)list->tail->value, elem5) == 0);
	assert(strcmp((char*)list->tail->prev->value, elem4) == 0);
	assert(compareStrings(list->head->value, (void*)elem1) == 1);
	assert(compareStrings(list->tail->value, (void*)elem5) == 1);
	assert(compareStrings(list->head->next->next->value, list->tail->prev->prev->value) == 1);

	freeDoubleLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test findElementByValue() function
void testFindElementByValue() {
	printf("test findElementByValue() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50], elem5[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");
	strcpy(elem5, "www.linkedin.com");

	DoubleLinkedList* list = NULL;
	Node* node;

	list = createEmptyDoubleLinkedList(compareStrings);
	node = findElementByValue(list, (void*)elem1);
	assert(node == NULL);

	addItemToDoubleLinkedList(list, (void*)elem1);
	assert(list->length == 1);
	node = findElementByValue(list, (void*)elem2);
	assert(node == NULL);

	node = findElementByValue(list, (void*)elem1);
	assert(node != NULL);
	assert(node == list->head);
	assert(node == list->tail);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(compareStrings(node->value, (void*)elem1) == 1);
	assert(compareStrings(node->value, (void*)elem2) == 0);

	addItemToDoubleLinkedList(list, (void*)elem2);
	node = findElementByValue(list, (void*)elem3);
	assert(node == NULL);

	node = findElementByValue(list, (void*)elem1);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(node->next == list->tail);
	assert(strcmp((char*)node->next->value, elem2) == 0);
	assert(strcmp((char*)node->next->prev->value, elem1) == 0);
	assert(compareStrings(node->value, (void*)elem1) == 1);

	node = findElementByValue(list, (void*)elem2);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(node->prev == list->head);
	assert(strcmp((char*)node->prev->value, elem1) == 0);
	assert(strcmp((char*)node->prev->next->value, elem2) == 0);
	assert(compareStrings(node->value, (void*)elem2) == 1);

	addItemToDoubleLinkedList(list, (void*)elem3);
	node = findElementByValue(list, (void*)elem2);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(node->prev == list->head);
	assert(node->next == list->tail);
	assert(strcmp((char*)node->prev->next->value, elem2) == 0);
	assert(strcmp((char*)node->next->prev->value, elem2) == 0);
	assert(compareStrings(node->value, (void*)elem1) == 0);
	assert(compareStrings(node->value, (void*)elem2) == 1);

	node = findElementByValue(list, (void*)elem4);
	assert(node == NULL);

	addItemToDoubleLinkedList(list, (void*)elem4);
	node = findElementByValue(list, (void*)elem3);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem3) == 0);
	assert(node->next == list->tail);
	assert(node->prev->prev == list->head);
	assert(strcmp((char*)node->prev->value, elem2) == 0);
	assert(strcmp((char*)node->prev->prev->value, elem1) == 0);
	assert(strcmp((char*)node->next->value, elem4) == 0);
	assert(strcmp((char*)node->prev->next->value, elem3) == 0);
	assert(strcmp((char*)node->next->prev->value, elem3) == 0);
	assert(compareStrings(node->value, (void*)elem1) == 0);
	assert(compareStrings(node->value, (void*)elem3) == 1);

	node = findElementByValue(list, (void*)elem5);
	assert(node == NULL);

	addItemToDoubleLinkedList(list, (void*)elem5);
	node = findElementByValue(list, (void*)elem5);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem5) == 0);
	assert(node->next == NULL);
	assert(node->prev->prev->prev->prev == list->head);
	assert(strcmp((char*)node->prev->value, elem4) == 0);
	assert(strcmp((char*)node->prev->prev->value, elem3) == 0);
	assert(compareStrings(node->value, (void*)elem1) == 0);
	assert(compareStrings(node->value, (void*)elem5) == 1);
	assert(compareStrings(node->value, node->prev->value) == 0);
	assert(compareStrings(node->value, node->prev->next->value) == 1);

	freeDoubleLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test removeItemFromDoubleLinkedList() function
void testRemoveItemFromDoubleLinkedList() {
	printf("test removeItemFromDoubleLinkedList() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	DoubleLinkedList* list = NULL;
	Node* node;

	list = createEmptyDoubleLinkedList(compareStrings);
	node = removeItemFromDoubleLinkedList(list, (void*)elem1);
	assert(node == NULL);
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);

	addItemToDoubleLinkedList(list, (void*)elem1);
	assert(list->length == 1);
	node = removeItemFromDoubleLinkedList(list, (void*)elem2);
	assert(node == NULL);
	assert(list->length == 1);
	assert(list->head != NULL);
	assert(list->tail != NULL);
	assert(list->head == list->tail);
	assert(strcmp((char*)list->head->value, elem1) == 0);
	assert(strcmp((char*)list->tail->value, elem1) == 0);

	node = removeItemFromDoubleLinkedList(list, (void*)elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	free(node);
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);

	addItemToDoubleLinkedList(list, (void*)elem1);
	addItemToDoubleLinkedList(list, (void*)elem2);
	assert(list->length == 2);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	node = removeItemFromDoubleLinkedList(list, (void*)elem3);
	assert(node == NULL);
	assert(list->length == 2);
	assert(list->head->next == list->tail);
	assert(list->tail->prev == list->head);
	assert(strcmp((char*)list->head->value, elem1) == 0);
	assert(strcmp((char*)list->tail->value, elem2) == 0);

	node = removeItemFromDoubleLinkedList(list, (void*)elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	free(node);
	assert(list->length == 1);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(list->head == list->tail);
	assert(strcmp((char*)list->head->value, elem2) == 0);
	assert(strcmp((char*)list->tail->value, elem2) == 0);

	addItemToDoubleLinkedList(list, (void*)elem1);
	addItemToDoubleLinkedList(list, (void*)elem3);
	assert(list->length == 3);
	node = removeItemFromDoubleLinkedList(list, (void*)elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	free(node);
	assert(list->length == 2);
	assert(list->tail->prev == list->head);
	assert(list->head->next == list->tail);
	assert(strcmp((char*)list->tail->value, elem3) == 0);
	assert(strcmp((char*)list->tail->prev->value, elem2) == 0);

	node = removeItemFromDoubleLinkedList(list, (void*)elem3);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem3) == 0);
	free(node);
	assert(list->length == 1);
	assert(list->head == list->tail);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(strcmp((char*)list->head->value, elem2) == 0);
	assert(strcmp((char*)list->tail->value, elem2) == 0);

	addItemToDoubleLinkedList(list, (void*)elem1);
	addItemToDoubleLinkedList(list, (void*)elem3);
	addItemToDoubleLinkedList(list, (void*)elem4);
	assert(list->length == 4);
	node = removeItemFromDoubleLinkedList(list, (void*)elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	free(node);
	assert(list->length == 3);
	assert(list->head->next->next == list->tail);
	assert(list->tail->prev->prev == list->head);
	assert(list->head->next == list->tail->prev);
	assert(strcmp((char*)list->head->next->value, elem3) == 0);
	assert(strcmp((char*)list->tail->prev->prev->value, elem2) == 0);

	freeDoubleLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

// test all methods
void testAllMethods() {
	printf("test all methods.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50], elem5[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");
	strcpy(elem5, "www.linkedin.com");

	DoubleLinkedList* list = NULL;
	Node* node;

	list = createEmptyDoubleLinkedList(compareStrings);
	assert(list->length == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);

	addItemToDoubleLinkedList(list, (void*)elem1);
	addItemToDoubleLinkedList(list, (void*)elem2);
	addItemToDoubleLinkedList(list, (void*)elem3);
	assert(list->length == 3);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(list->head->next->next == list->tail);
	assert(list->tail->prev->prev == list->head);
	assert(strcmp((char*)list->head->next->value, elem2) == 0);
	assert(strcmp((char*)list->tail->prev->value, elem2) == 0);

	node = findElementByValue(list, (void*)elem4);
	assert(node == NULL);

	node = findElementByValue(list, (void*)elem2);
	assert(node != NULL);
	assert(node->prev == list->head);
	assert(node->next = list->tail);
	assert(strcmp((char*)node->prev->value, elem1) == 0);
	assert(strcmp((char*)node->next->value, elem3) == 0);
	assert(compareStrings(node->value, (void*)elem2) == 1);
	assert(compareStrings(node->value, node->prev->value) == 0);

	node = removeItemFromDoubleLinkedList(list, (void*)elem4);
	assert(node == NULL);
	assert(list->length == 3);

	node = removeItemFromDoubleLinkedList(list, (void*)elem2);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	free(node);
	assert(list->length == 2);
	node = findElementByValue(list, (void*)elem2);
	assert(node == NULL);

	node = findElementByValue(list, (void*)elem1);
	assert(node != NULL);
	assert(node == list->head);
	assert(node->next == list->tail);
	assert(list->tail->prev == node);
	assert(strcmp((char*)node->next->value, elem3) == 0);
	assert(compareStrings(node->value, (void*)elem1) == 1);

	addItemToDoubleLinkedList(list, (void*)elem2);
	addItemToDoubleLinkedList(list, (void*)elem4);
	addItemToDoubleLinkedList(list, (void*)elem5);
	assert(list->length == 5);
	assert(strcmp((char*)list->head->value, elem1) == 0);
	assert(strcmp((char*)list->tail->value, elem5) == 0);

	node = findElementByValue(list, (void*)elem2);
	assert(node != NULL);
	assert(node->prev == list->head->next);
	assert(strcmp((char*)node->prev->value, elem3) == 0);
	assert(node->next == list->tail->prev);
	assert(strcmp((char*)node->next->value, elem4) == 0);

	node = removeItemFromDoubleLinkedList(list, (void*)elem2);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	free(node);
	assert(list->length == 4);
	node = findElementByValue(list, (void*)elem2);
	assert(node == NULL);

	node = findElementByValue(list, (void*)elem4);
	assert(node != NULL);
	assert(node->next == list->tail);
	assert(strcmp((char*)node->next->value, elem5) == 0);
	assert(node->prev->prev == list->head);
	assert(strcmp((char*)node->prev->value, elem3) == 0);

	node = removeItemFromDoubleLinkedList(list, (void*)elem5);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem5) == 0);
	free(node);
	assert(list->length == 3);
	node = findElementByValue(list, (void*)elem4);
	assert(node != NULL);
	assert(node == list->tail);
	assert(strcmp((char*)node->value, elem4) == 0);
	assert(node->prev->prev == list->head);
	assert(strcmp((char*)node->prev->value, elem3) == 0);

	node = removeItemFromDoubleLinkedList(list, (void*)elem5);
	assert(node == NULL);
	assert(list->length == 3);

	node = removeItemFromDoubleLinkedList(list, (void*)elem1);
	assert(node != NULL);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	free(node);
	assert(list->length == 2);
	assert(list->head->prev == NULL);
	assert(list->tail->next == NULL);
	assert(strcmp((char*)list->head->value, elem3) == 0);
	assert(strcmp((char*)list->tail->value, elem4) == 0);
	assert(list->head->next == list->tail);
	assert(list->tail->prev == list->head);

	freeDoubleLinkedListMemory(list);
	free(list);
	list = NULL;

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testNodeStructure();

	testCreateEmptyDoubleLinkedList();

	testAddItemToDoubleLinkedList();

	testFindElementByValue();

	testRemoveItemFromDoubleLinkedList();

	testAllMethods();

	return 0;
}