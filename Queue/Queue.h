#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "utils/utils.h"

// create an empty queue (the method is a kind of C++ constructor)
Queue* createEmptyQueue(int size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	queue->size = size;
	queue->length = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

// add an item to queue
void add(Queue* queue, void* value) {
	// queue is full
	if (queue->length == queue->size) {
		return;
	}

	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;

	if (queue->length == 0) {
		queue->head = queue->tail = node;
	} else {
		queue->tail->next = node;
		queue->tail = node;
	}

	++queue->length;
}

// remove an item
Node* erase(Queue* queue) {
	// queue is empty
	if (queue->length == 0) {
		return NULL;
	}

	Node* node = queue->head;
	queue->head = node->next;
	if (queue->length == 1) {
		queue->tail = NULL;
	}

	--queue->length;

	node->next = NULL;
	return node;
}

// free memory used
void freeQueueMemory(Queue* queue) {
	if (!queue || queue->length == 0) {
		return;
	}

	Node* node = queue->head;
	Node* helpNode = queue->head;
	node = node->next;

	while (node != NULL) {
		free(helpNode);
		helpNode = node;
		node = node->next;
	}

	free(helpNode);
}

#endif // QUEUE_H