#ifndef UTILS_H
#define UTILS_H

// describes the structure of the node 
typedef struct Node {
	void* value;
	struct Node* next;
	struct Node* prev;
} Node;

// describes a DoubleLinkedList
typedef struct {
	Node* head;
	Node* tail;
	int length;
	unsigned int (*compare)(void*, void*);
} DoubleLinkedList;

#endif // UTILS_H