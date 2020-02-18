#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "Stack.h"

// test createEmptyStack() function
void testCreateEmptyStack() {
	printf("test createEmptyStack() function.\n");

	int size = 50;
	Stack* stack = NULL;

	stack = createEmptyStack(size);
	assert(stack->length == 0);
	assert(stack->size == size);
	assert(stack->head == NULL);

	freeStackMemory(stack);
	free(stack);

	printf("\n");
}

// test push() function
void testPush() {
	printf("test push() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	int size = 3;
	Stack* stack = NULL;

	stack = createEmptyStack(size);
	assert(stack->length == 0);
	assert(stack->size == size);
	assert(stack->head == NULL);

	push(stack, (void*)elem1);
	assert(stack->length == 1);
	assert(stack->size == size);
	assert(stack->head != NULL);
	assert(stack->head->next == NULL);
	assert(strcmp((char*)stack->head->value, elem1) == 0);

	push(stack, (void*)elem2);
	assert(stack->length == 2);
	assert(stack->size == size);
	assert(strcmp((char*)stack->head->value, elem2) == 0);

	push(stack, (void*)elem3);
	assert(stack->length == 3);
	assert(stack->size == size);
	assert(strcmp((char*)stack->head->value, elem3) == 0);

	push(stack, (void*)elem4);
	assert(stack->length == 3);
	assert(stack->size == size);
	assert(strcmp((char*)stack->head->value, elem3) == 0);

	freeStackMemory(stack);
	free(stack);

	printf("\n");
}

// test pop() function
void testPop() {
	printf("test pop() function.\n");

	char elem1[50], elem2[50], elem3[50], elem4[50];
	strcpy(elem1, "www.facebook.com");
	strcpy(elem2, "studenti.pub.ro");
	strcpy(elem3, "www.geeksforgeeks.org");
	strcpy(elem4, "stackoverflow.com");

	int size = 4;
	Stack* stack = NULL;
	Node* node;

	stack = createEmptyStack(size);
	node = pop(stack);
	assert(node == NULL);

	push(stack, (void*)elem1);
	assert(stack->length == 1);
	node = pop(stack);
	assert(node != NULL);
	assert(node != stack->head);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(stack->length == 0);
	assert(stack->head == NULL);
	assert(stack->size == size);
	free(node);

	push(stack, (void*)elem2);
	push(stack, (void*)elem3);
	push(stack, (void*)elem4);
	assert(stack->length == 3);

	node = pop(stack);
	assert(stack->length == 2);
	assert(node != NULL);
	assert(node != stack->head);
	assert(strcmp((char*)node->value, elem4) == 0);
	assert(strcmp((char*)stack->head->value, elem3) == 0);
	assert(stack->size == size);
	free(node);

	node = pop(stack);
	assert(stack->length == 1);
	assert(node != NULL);
	assert(node != stack->head);
	assert(strcmp((char*)node->value, elem3) == 0);
	assert(strcmp((char*)stack->head->value, elem2) == 0);
	assert(stack->size == size);
	free(node);

	node = pop(stack);
	assert(stack->length == 0);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(stack->head == NULL);
	assert(stack->size == size);
	free(node);

	node = pop(stack);
	assert(stack->length == 0);
	assert(node == NULL);
	assert(stack->size == size);

	freeStackMemory(stack);
	free(stack);

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

	int size = 4;
	Stack* stack = NULL;
	Node* node;

	stack = createEmptyStack(size);
	assert(stack->size == size);
	assert(stack->length == 0);
	assert(stack->head == NULL);

	node = pop(stack);
	assert(node == NULL);

	push(stack, (void*)elem1);
	push(stack, (void*)elem2);
	push(stack, (void*)elem3);
	assert(stack->size == size);
	assert(stack->length == 3);

	node = pop(stack);
	assert(stack->length == 2);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem3) == 0);
	assert(strcmp((char*)stack->head->value, elem2) == 0);
	free(node);

	node = pop(stack);
	assert(stack->length == 1);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(strcmp((char*)stack->head->value, elem1) == 0);
	free(node);

	node = pop(stack);
	assert(stack->length == 0);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem1) == 0);
	assert(stack->head == NULL);
	free(node);

	node = pop(stack);
	assert(stack->length == 0);
	assert(node == NULL);

	push(stack, (void*)elem1);
	push(stack, (void*)elem2);
	push(stack, (void*)elem3);
	assert(stack->size == size);
	assert(stack->length == 3);

	node = pop(stack);
	assert(stack->length == 2);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem3) == 0);
	assert(strcmp((char*)stack->head->value, elem2) == 0);
	free(node);

	push(stack, (void*)elem4);
	push(stack, (void*)elem5);
	assert(stack->length == 4);

	node = pop(stack);
	assert(stack->length == 3);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem5) == 0);
	assert(strcmp((char*)stack->head->value, elem4) == 0);
	free(node);

	node = pop(stack);
	assert(stack->length == 2);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem4) == 0);
	assert(strcmp((char*)stack->head->value, elem2) == 0);
	free(node);

	node = pop(stack);
	assert(stack->length == 1);
	assert(node != NULL);
	assert(strcmp((char*)node->value, elem2) == 0);
	assert(strcmp((char*)stack->head->value, elem1) == 0);
	free(node);

	assert(stack->length == 1);
	push(stack, (void*)elem2);
	push(stack, (void*)elem3);
	push(stack, (void*)elem4);
	push(stack, (void*)elem5);
	assert(stack->length == 4);
	assert(strcmp((char*)stack->head->value, elem4) == 0);

	freeStackMemory(stack);
	free(stack);

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testCreateEmptyStack();

	testPush();

	testPop();

	testAllMethods();

	return 0;
}