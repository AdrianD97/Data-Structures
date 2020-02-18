#ifndef UTILS_H
#define UTILS_H

// describes the structure of the node 
typedef struct Node {
	void* value;
	struct Node* next;
} Node;

// describes a Stack
typedef struct {
	Node* head;
	Node* tail;
	int length;
	int size;
} Queue;

#endif // UTILS_H