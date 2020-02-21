#ifndef UTILS_H
#define UTILS_H

typedef struct Node {
	void* value;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct {
	Node* root;
	int (*compare)(void*, void*);
} BinarySearchTree;

#endif // UTILS_H