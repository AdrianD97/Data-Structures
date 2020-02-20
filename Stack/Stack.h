#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "utils/utils.h"

// create an empty stack (the method is a kind of C++ constructor)
Stack* createEmptyStack(int size) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));

	stack->size = size;
	stack->length = 0;
	stack->head = NULL;

	return stack;
}

// add an element to stack
void push(Stack* stack, void* value) {
	// stack is full
	if (stack->length == stack->size) {
		return;
	}

	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;

	// stack is empty
	if (stack->length == 0) {
		++stack->length;
		stack->head = node;
		return;
	}

	node->next = stack->head;
	stack->head = node;
	++stack->length;
}

// pop an element
Node* pop(Stack* stack) {
	if (stack->length == 0) {
		return NULL;
	}

	Node* node = stack->head;
	stack->head = node->next;
	--stack->length;

	node->next = NULL;
	return node;
}

// free memory used
void freeStackMemory(Stack* stack) {
	if (stack->length == 0) {
		return;
	}

	Node* node = stack->head;
	Node* helpNode = stack->head;
	node = node->next;

	while (node != NULL) {
		free(helpNode);
		helpNode = node;
		node = node->next;
	}

	free(helpNode);
}

#endif // STACK_H