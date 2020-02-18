#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "Queue.h"

// test createEmptyQueue() function
void testCreateEmptyQueue() {
	printf("test createEmptyQueue() function.\n");

	int size = 500;
	Queue* queue = NULL;

	queue = createEmptyQueue(size);
	assert(queue->size == size);
	assert(queue->length == 0);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);

	freeQueueMemory(queue);
	free(queue);
	queue = NULL;

	printf("\n");
}

// test add() function
void testAdd() {
	printf("test add() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	int size = 3;
	Queue* queue = NULL;

	queue = createEmptyQueue(size);
	assert(queue->size == size);
	assert(queue->length == 0);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);

	add(queue, (void*)elem1);
	assert(queue->size == size);
	assert(queue->length == 1);
	assert(queue->head == queue->tail);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem1) == 0);

	add(queue, (void*)elem2);
	assert(queue->size == size);
	assert(queue->length == 2);
	assert(queue->head->next == queue->tail);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem2) == 0);

	add(queue, (void*)elem3);
	assert(queue->size == size);
	assert(queue->length == 3);
	assert(queue->head->next->next == queue->tail);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem3) == 0);

	add(queue, (void*)elem4);
	assert(queue->size == size);
	assert(queue->length == 3);
	assert(queue->head->next->next == queue->tail);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem3) == 0);

	freeQueueMemory(queue);
	free(queue);
	queue = NULL;

	printf("\n");
}

// test erase() function
void testErase() {
	printf("test erase() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	int size = 4;
	Queue* queue = NULL;
	Node* node;

	queue = createEmptyQueue(size);
	assert(queue->size == size);
	assert(queue->length == 0);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);

	node = erase(queue);
	assert(node == NULL);
	assert(queue->size == size);
	assert(queue->length == 0);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);

	add(queue, (void*)elem1);
	assert(queue->length == 1);
	assert(queue->size == size);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(queue->size == size);
	assert(queue->length == 0);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);
	free(node);

	add(queue, (void*)elem1);
	add(queue, (void*)elem2);
	add(queue, (void*)elem3);
	assert(queue->length == 3);
	assert(queue->size == size);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(queue->size == size);
	assert(queue->length == 2);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem2) == 0);
	assert(strcmp((char*)queue->tail->value, elem3) == 0);
	free(node);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(queue->size == size);
	assert(queue->length == 1);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem3) == 0);
	assert(strcmp((char*)queue->tail->value, elem3) == 0);
	free(node);

	add(queue, (void*)elem2);
	add(queue, (void*)elem1);
	add(queue, (void*)elem4);
	assert(queue->length == 4);
	assert(queue->size == size);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem3) == 0);
	assert(queue->size == size);
	assert(queue->length == 3);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem2) == 0);
	assert(strcmp((char*)queue->tail->value, elem4) == 0);
	free(node);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(queue->size == size);
	assert(queue->length == 2);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem4) == 0);
	free(node);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(queue->size == size);
	assert(queue->length == 1);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem4) == 0);
	assert(strcmp((char*)queue->tail->value, elem4) == 0);
	free(node);

	freeQueueMemory(queue);
	free(queue);
	queue = NULL;

	printf("\n");
}

// test all methods
void testAllMethods() {
	printf("test all methods.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	int size = 4;
	Queue* queue = NULL;
	Node* node;

	queue = createEmptyQueue(size);
	assert(queue->size == size);
	assert(queue->length == 0);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);

	add(queue, (void*)elem1);
	add(queue, (void*)elem2);
	add(queue, (void*)elem3);
	assert(queue->length == 3);
	assert(queue->size == size);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem3) == 0);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(queue->size == size);
	assert(queue->length == 2);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem2) == 0);
	assert(strcmp((char*)queue->tail->value, elem3) == 0);
	free(node);

	add(queue, (void*)elem4);
	add(queue, (void*)elem1);
	assert(queue->length == 4);
	assert(queue->size == size);
	assert(strcmp((char*)queue->head->value, elem2) == 0);
	assert(strcmp((char*)queue->tail->value, elem1) == 0);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(queue->size == size);
	assert(queue->length == 3);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem3) == 0);
	assert(strcmp((char*)queue->tail->value, elem1) == 0);
	free(node);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem3) == 0);
	assert(queue->size == size);
	assert(queue->length == 2);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem4) == 0);
	assert(strcmp((char*)queue->tail->value, elem1) == 0);
	free(node);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem4) == 0);
	assert(queue->size == size);
	assert(queue->length == 1);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem1) == 0);
	free(node);

	add(queue, (void*)elem4);
	assert(queue->length == 2);
	assert(queue->size == size);
	assert(strcmp((char*)queue->head->value, elem1) == 0);
	assert(strcmp((char*)queue->tail->value, elem4) == 0);

	node = erase(queue);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(queue->size == size);
	assert(queue->length == 1);
	assert(node != queue->head);
	assert(strcmp((char*)queue->head->value, elem4) == 0);
	assert(strcmp((char*)queue->tail->value, elem4) == 0);
	free(node);

	add(queue, (void*)elem2);
	add(queue, (void*)elem3);
	assert(queue->length == 3);
	assert(queue->size == size);
	assert(strcmp((char*)queue->head->value, elem4) == 0);
	assert(strcmp((char*)queue->tail->value, elem3) == 0);

	add(queue, (void*)elem2);
	add(queue, (void*)elem3);
	assert(queue->length == 4);
	assert(queue->size == size);
	assert(strcmp((char*)queue->head->value, elem4) == 0);
	assert(strcmp((char*)queue->head->next->value, elem2) == 0);
	assert(strcmp((char*)queue->head->next->next->value, elem3) == 0);
	assert(strcmp((char*)queue->head->next->next->next->value, elem2) == 0);
	assert(strcmp((char*)queue->tail->value, elem2) == 0);

	freeQueueMemory(queue);
	free(queue);
	queue = NULL;

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testCreateEmptyQueue();

	testAdd();

	testErase();

	testAllMethods();

	return 0;
}