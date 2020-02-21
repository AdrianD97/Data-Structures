#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdlib.h>

#include "utils/utils.h"

// create an empty Binary Search Tree (the method is a kind of C++ constructor)
BinarySearchTree* createEmptyBinarySearchTree(int (*compare)(void*, void*)) {
	BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));

	tree->root = NULL;
	tree->compare = compare;

	return tree;
}

// add an item to Binary Search Tree
void add(Node* node1, int (*compare)(void*, void*), Node* node2) {
	if (compare(node2->value, node1->value) < 0) {
		if (!node1->left) {
			node1->left = node2;
			node2->parent = node1;
		} else {
			add(node1->left, compare, node2);
		}
	} else {
		if (!node1->right) {
			node1->right = node2;
			node2->parent = node1;
		} else {
			add(node1->right, compare, node2);
		}
	}
}

void addItemToBinarySearchTree(BinarySearchTree* tree, void* value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->parent = node->left = node->right = NULL;

	// if empty tree
	if (!tree->root) {
		tree->root = node;
		return;
	}

	add(tree->root, tree->compare, node);
}

// find an element by value
Node* get(Node* node, int (*compare)(void*, void*), void* value) {
	if (!node) {
		return NULL;
	}

	int res = compare(value, node->value);

	if (res == 0) {
		return node;
	}

	if (res < 0) {
		return get(node->left, compare, value);
	}

	return get(node->right, compare, value);
}

Node* getElementByValue(const BinarySearchTree* tree, void* value) {
	if (!tree) {
		return NULL;
	}

	return get(tree->root, tree->compare, value);
}

// remove an item from tree
Node* findMinimumFromRightSubtree(Node* node) {
	while (node->left) {
		node = node->left;
	}

	return node;
}

void removeHelper(BinarySearchTree* tree, Node* node) {
	if (!node->left && !node->right) { // node has no childs
		if (!node->parent) { // node is root of the tree
			tree->root = NULL;
			return;
		}

		if (node->parent->left == node) {
			node->parent->left = NULL;
		} else {
			node->parent->right = NULL;
		}
	} else if (node->left) { // node has left child
		if (!node->parent) { // node is root of the tree
			tree->root = node->left;
			tree->root->parent = NULL;
			return;
		}

		if (node->parent->left == node) {
			node->parent->left = node->left;
		} else {
			node->parent->right = node->left;
		}
		node->left->parent = node->parent;
	} else { // node has right child
		if (!node->parent) { // node is root of the tree
			tree->root = node->right;
			tree->root->parent = NULL;
			return;
		}

		if (node->parent->left == node) {
			node->parent->left = node->right;
		} else {
			node->parent->right = node->right;
		}

		node->right->parent = node->parent;
	}
}

Node* removeItemFromBinarySearchTree(BinarySearchTree* tree, void* value) {
	if (!tree) {
		return NULL;
	}

	Node* node = getElementByValue(tree, value);

	if (!node) {
		return NULL;
	}

	if (node->left && node->right) { // node has both childs
		Node* minim = findMinimumFromRightSubtree(node->right);
		void* temp = node->value;
		node->value = minim->value;
		minim->value = temp;
		node = minim;
	}

	removeHelper(tree, node);

	node->parent = node->left = node->right = NULL;
	return node;
}

// free used memory
void freeNodesMemory(Node* node) {
	if (!node) {
		return;
	}

	freeNodesMemory(node->left);
	freeNodesMemory(node->right);
	free(node);
}

void freeBinarySearchTreeMemory(BinarySearchTree* tree) {
	if (!tree) {
		return;
	}

	freeNodesMemory(tree->root);
}

#endif // BINARY_SEARCH_TREE_H