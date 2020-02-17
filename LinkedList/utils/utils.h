#ifndef UTILS_H
#define UTILS_H

#define MAX 50

// describes the structure of the node 
typedef struct Node {
	char value[MAX];
	struct Node* next;
} Node;

// describes a LinkedList
typedef struct {
	Node* head;
	Node* tail;
	int length;
} LinkedList;

#endif // UTILS_H