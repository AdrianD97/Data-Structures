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
	int length;
	int size;
} Stack;

#endif // UTILS_H