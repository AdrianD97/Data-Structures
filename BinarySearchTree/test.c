#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "BinarySearchTree.h"
#include "../compare_functions/compare_functions_.h"

// test Node structure
void testNodeStructure() {
	printf("test Node structure.\n");
	char* val = "www.facebook.com";

	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node->value = (void*)val;
	node->parent = node->left = node->right = NULL;

	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(strcmp((char*)node->value, val) == 0);
	free(node);

	int val_i = 100;
	node = (Node*)malloc(sizeof(Node));
	node->value = (void*)&val_i;
	node->parent = node->left = node->right = NULL;

	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(*(int*)node->value == val_i);
	free(node);

	printf("\n");
}

// test createEmptyBinarySearchTree() function
void testCreateEmptyBinarySearchTree() {
	printf("test createEmptyBinarySearchTree() function.\n");

	BinarySearchTree* tree = createEmptyBinarySearchTree(compareIntegers);

	assert(tree != NULL);
	assert(tree->root == NULL);
	assert(tree->compare == compareIntegers);

	freeBinarySearchTreeMemory(tree);
	free(tree);

	printf("\n");
}

// test addItemToBinarySearchTree() function
void testAddItemToBinarySearchTree() {
	printf("test addItemToBinarySearchTree() function.\n");

	// nodes values of int type
	int val1 = 1, val2 = 3, val3 = 7, val4 = 2, val5 = -3;

	BinarySearchTree* tree = createEmptyBinarySearchTree(compareIntegers);

	assert(tree != NULL);
	assert(tree->root == NULL);
	assert(tree->compare == compareIntegers);

	addItemToBinarySearchTree(tree, (void*)&val1);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)tree->root->value == val1);

	addItemToBinarySearchTree(tree, (void*)&val2);
	assert(tree->root != NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)tree->root->value == val1);
	assert(*(int*)tree->root->right->value == val2);
	assert(tree->root->right->left == NULL);
	assert(tree->root->right->right == NULL);
	assert(*(int*)tree->root->right->parent->value == val1);

	addItemToBinarySearchTree(tree, (void*)&val3);
	assert(tree->root != NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right != NULL);
	assert(tree->root->right->right != NULL);
	assert(*(int*)tree->root->value == val1);
	assert(*(int*)tree->root->right->value == val2);
	assert(*(int*)tree->root->right->right->value == val3);
	assert(tree->root->right->left == NULL);
	assert(tree->root->right->right != NULL);
	assert(tree->root->right->right->left == NULL);
	assert(tree->root->right->right->right == NULL);
	assert(compareIntegers(tree->root->right->value, (void*)&val2) == 0);
	assert(*(int*)tree->root->right->right->parent->value == val2);

	addItemToBinarySearchTree(tree, (void*)&val4);
	assert(tree->root != NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right != NULL);
	assert(tree->root->right->right != NULL);
	assert(*(int*)tree->root->value == val1);
	assert(*(int*)tree->root->right->value == val2);
	assert(*(int*)tree->root->right->right->value == val3);
	assert(tree->root->right->left != NULL);
	assert(tree->root->right->left->left == NULL);
	assert(tree->root->right->left->right == NULL);
	assert(*(int*)tree->root->right->left->value == val4);
	assert(tree->root->right->right != NULL);
	assert(tree->root->right->right->left == NULL);
	assert(tree->root->right->right->right == NULL);
	assert(compareIntegers(tree->root->right->left->value, (void*)&val4) == 0);
	assert(*(int*)tree->root->right->left->parent->value == val2);

	addItemToBinarySearchTree(tree, (void*)&val5);
	assert(tree->root != NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)tree->root->left->value == val5);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(*(int*)tree->root->left->parent->value == val1);

	addItemToBinarySearchTree(tree, (void*)&val2);
	assert(tree->root != NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(tree->root->right->right != NULL);
	assert(*(int*)tree->root->value == val1);
	assert(*(int*)tree->root->right->value == val2);
	assert(*(int*)tree->root->right->right->value == val3);
	assert(tree->root->right->left != NULL);
	assert(tree->root->right->left->left == NULL);
	assert(tree->root->right->left->right == NULL);
	assert(*(int*)tree->root->right->left->value == val4);
	assert(tree->root->right->right != NULL);
	assert(tree->root->right->right->left != NULL);
	assert(tree->root->right->right->left->left == NULL);
	assert(tree->root->right->right->left->right == NULL);
	assert(*(int*)tree->root->right->right->left->value == val2);
	assert(tree->root->right->right->right == NULL);
	assert(compareIntegers(tree->root->right->left->value, (void*)&val4) == 0);
	assert(*(int*)tree->root->right->right->left->parent->value == val3);

	freeBinarySearchTreeMemory(tree);
	free(tree);

	// nodes values of string type
	char* val_str1 = "www.facebook.com";
	char* val_str2 = "studenti.pub.ro";
	char* val_str3 = "www.geeksforgeeks.org";
	char* val_str4 = "stackoverflow.com";

	tree = createEmptyBinarySearchTree(compareStrings);

	assert(tree != NULL);
	assert(tree->root == NULL);
	assert(tree->compare == compareStrings);

	addItemToBinarySearchTree(tree, (void*)val_str1);
	assert(tree != NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right == NULL);
	assert(strcmp((char*)tree->root->value, val_str1) == 0);

	addItemToBinarySearchTree(tree, (void*)val_str2);
	assert(tree != NULL);
	assert(tree->root != NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->right == NULL);
	assert(strcmp((char*)tree->root->value, val_str1) == 0);
	assert(strcmp((char*)tree->root->left->value, val_str2) == 0);
	assert(strcmp((char*)tree->root->left->parent->value, val_str1) == 0);

	addItemToBinarySearchTree(tree, (void*)val_str3);
	assert(tree != NULL);
	assert(tree->root != NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->right->left == NULL);
	assert(tree->root->right->right == NULL);
	assert(strcmp((char*)tree->root->value, val_str1) == 0);
	assert(strcmp((char*)tree->root->left->value, val_str2) == 0);
	assert(strcmp((char*)tree->root->right->value, val_str3) == 0);
	assert(strcmp((char*)tree->root->right->parent->value, val_str1) == 0);

	addItemToBinarySearchTree(tree, (void*)val_str4);
	assert(tree != NULL);
	assert(tree->root != NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(tree->root->left->left != NULL);
	assert(tree->root->left->left->left == NULL);
	assert(tree->root->left->left->right == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->right->left == NULL);
	assert(tree->root->right->right == NULL);
	assert(strcmp((char*)tree->root->value, val_str1) == 0);
	assert(strcmp((char*)tree->root->left->value, val_str2) == 0);
	assert(strcmp((char*)tree->root->right->value, val_str3) == 0);
	assert(strcmp((char*)tree->root->left->left->value, val_str4) == 0);
	assert(strcmp((char*)tree->root->left->left->parent->value, val_str2) == 0);

	freeBinarySearchTreeMemory(tree);
	free(tree);

	printf("\n");
}

// test findElemengetElementByValuetByValue() funtion
void testFindElementByValue() {
	printf("test getElementByValue() funtion.\n");

	int val1 = 1, val2 = 3, val3 = 7, val4 = 2, val5 = -3, val6 = 90;

	BinarySearchTree* tree = createEmptyBinarySearchTree(compareIntegers);
	Node* node;

	assert(tree != NULL);
	assert(tree->root == NULL);
	assert(tree->compare == compareIntegers);


	node = getElementByValue(NULL, (void*)&val1);
	assert(node == NULL);

	node = getElementByValue(tree, (void*)&val1);
	assert(node == NULL);

	addItemToBinarySearchTree(tree, (void*)&val1);
	node = getElementByValue(tree, (void*)&val2);
	assert(node == NULL);

	node = getElementByValue(tree, (void*)&val1);
	assert(node != NULL);
	assert(node == tree->root);
	assert(*(int*)node->value == val1);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);

	addItemToBinarySearchTree(tree, (void*)&val2);
	node = getElementByValue(tree, (void*)&val2);
	assert(node != NULL);
	assert(*(int*)node->value == val2);
	assert(*(int*)node->parent->value == val1);
	assert(node->left == NULL);
	assert(node->right == NULL);

	addItemToBinarySearchTree(tree, (void*)&val3);
	addItemToBinarySearchTree(tree, (void*)&val4);

	node = getElementByValue(tree, (void*)&val5);
	assert(node == NULL);
	node = getElementByValue(tree, (void*)&val6);
	assert(node == NULL);

	node = getElementByValue(tree, (void*)&val2);
	assert(node != NULL);
	assert(*(int*)node->value == val2);
	assert(*(int*)node->right->value == val3);
	assert(*(int*)node->left->value == val4);
	assert(*(int*)node->parent->value == val1);

	addItemToBinarySearchTree(tree, (void*)&val5);
	addItemToBinarySearchTree(tree, (void*)&val2);

	node = getElementByValue(tree, (void*)&val1);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(*(int*)node->value == val1);
	assert(*(int*)node->right->value == val2);
	assert(*(int*)node->left->value == val5);

	node = getElementByValue(tree, (void*)&val3);
	assert(node != NULL);
	assert(*(int*)node->value == val3);
	assert(node->right == NULL);
	assert(*(int*)node->left->value == val2);
	assert(node->parent == tree->root->right);
	assert(*(int*)node->parent->value == val2);

	node = getElementByValue(tree, (void*)&val4);
	assert(node != NULL);
	assert(node->right == NULL);
	assert(node->left == NULL);
	assert(*(int*)node->value == val4);
	assert(*(int*)node->parent->value == val2);

	addItemToBinarySearchTree(tree, (void*)&val6);
	node = getElementByValue(tree, (void*)&val2);
	assert(node != NULL);
	assert(*(int*)node->value == val2);
	assert(node->right != NULL);
	assert(node->left != NULL);
	assert(*(int*)node->left->value == val4);
	assert(*(int*)node->right->value == val3);
	assert(*(int*)node->right->left->value == val2);
	assert(*(int*)node->right->right->value == val6);
	assert(node->right->right->left == NULL);
	assert(node->right->right->right == NULL);
	assert(*(int*)node->parent->value == val1);

	node = getElementByValue(tree, (void*)&val3);
	assert(node != NULL);
	assert(node->left != NULL);
	assert(node->right != NULL);
	assert(*(int*)node->value == val3);
	assert(*(int*)node->left->value == val2);
	assert(*(int*)node->right->value == val6);
	assert(*(int*)node->parent->value == val2);

	node = getElementByValue(tree, (void*)&val6);
	assert(node != NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(*(int*)node->value == val6);
	assert(*(int*)node->parent->value == val3);
	assert(*(int*)node->parent->parent->value == val2);
	assert(*(int*)node->parent->parent->parent->value == val1);
	assert(node->parent->parent->parent->parent == NULL);
	assert(*(int*)node->parent->parent->left->value == val4);

	freeBinarySearchTreeMemory(tree);
	free(tree);

	printf("\n");
}

// test removeItemFromBinarySearchTree() function
void testRemoveItemFromBinarySearchTree() {
	printf("test removeItemFromBinarySearchTree() function.\n");

	int val1 = 1, val2 = 3, val3 = 7, val4 = 2, val5 = -3, val6 = 90, val7 = -7;
	int val8 = 4;

	BinarySearchTree* tree = createEmptyBinarySearchTree(compareIntegers);
	Node* node;

	node = removeItemFromBinarySearchTree(NULL, (void*)&val1);
	assert(node == NULL);

	node = removeItemFromBinarySearchTree(tree, (void*)&val1);
	assert(node == NULL);

	addItemToBinarySearchTree(tree, (void*)&val1);
	node = removeItemFromBinarySearchTree(tree, (void*)&val2);
	assert(node == NULL);

	node = removeItemFromBinarySearchTree(tree, (void*)&val1);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root == NULL);
	assert(*(int*)node->value == val1);
	free(node);

	node = removeItemFromBinarySearchTree(tree, (void*)&val2);
	assert(node == NULL);

	addItemToBinarySearchTree(tree, (void*)&val1);
	addItemToBinarySearchTree(tree, (void*)&val5);

	node = removeItemFromBinarySearchTree(tree, (void*)&val2);
	assert(node == NULL);

	node = removeItemFromBinarySearchTree(tree, (void*)&val5);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val5);
	assert(*(int*)tree->root->value == val1);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val5);
	node = removeItemFromBinarySearchTree(tree, (void*)&val1);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val1);
	assert(*(int*)tree->root->value == val5);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val2);
	node = removeItemFromBinarySearchTree(tree, (void*)&val2);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val2);
	assert(*(int*)tree->root->value == val5);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val2);
	node = removeItemFromBinarySearchTree(tree, (void*)&val5);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left == NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val5);
	assert(*(int*)tree->root->value == val2);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val5);
	addItemToBinarySearchTree(tree, (void*)&val7);

	node = removeItemFromBinarySearchTree(tree, (void*)&val5);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val5);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val7);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->left->parent == tree->root);
	assert(*(int*)tree->root->left->parent->value == val2);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val4);
	node = removeItemFromBinarySearchTree(tree, (void*)&val7);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val7);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val4);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->left->parent == tree->root);
	assert(*(int*)tree->root->left->parent->value == val2);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val3);
	addItemToBinarySearchTree(tree, (void*)&val6);

	node = removeItemFromBinarySearchTree(tree, (void*)&val3);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)node->value == val3);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val4);
	assert(*(int*)tree->root->right->value == val6);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->right->left == NULL);
	assert(tree->root->right->right == NULL);
	assert(tree->root->right->parent == tree->root);
	assert(*(int*)tree->root->right->parent->value == val2);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val3);
	node = removeItemFromBinarySearchTree(tree, (void*)&val6);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)node->value == val6);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val4);
	assert(*(int*)tree->root->right->value == val3);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->right->left == NULL);
	assert(tree->root->right->right == NULL);
	assert(tree->root->right->parent == tree->root);
	assert(*(int*)tree->root->right->parent->value == val2);
	free(node);

	node = removeItemFromBinarySearchTree(tree, (void*)&val2);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val2);
	assert(*(int*)tree->root->value == val3);
	assert(*(int*)tree->root->left->value == val4);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->left->parent == tree->root);
	assert(*(int*)tree->root->left->parent->value == val3);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val1);
	addItemToBinarySearchTree(tree, (void*)&val8);
	addItemToBinarySearchTree(tree, (void*)&val2);

	node = removeItemFromBinarySearchTree(tree, (void*)&val4);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right == NULL);
	assert(*(int*)node->value == val4);
	assert(*(int*)tree->root->value == val3);
	assert(*(int*)tree->root->left->value == val2);
	assert(tree->root->left->left != NULL);
	assert(tree->root->left->right != NULL);
	assert(tree->root->left->parent == tree->root);
	assert(*(int*)tree->root->left->parent->value == val3);
	assert(*(int*)tree->root->left->left->value == val1);
	assert(*(int*)tree->root->left->right->value == val8);
	assert(tree->root->left->right->parent == tree->root->left);
	free(node);

	node = removeItemFromBinarySearchTree(tree, (void*)&val3);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)node->value == val3);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val1);
	assert(*(int*)tree->root->right->value == val8);
	assert(tree->root->left->left == NULL);
	assert(tree->root->left->right == NULL);
	assert(tree->root->left->parent == tree->root);
	assert(tree->root->right->parent == tree->root);
	assert(tree->root->left->parent == tree->root);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val2);
	addItemToBinarySearchTree(tree, (void*)&val3);
	addItemToBinarySearchTree(tree, (void*)&val8);
	addItemToBinarySearchTree(tree, (void*)&val6);

	node = removeItemFromBinarySearchTree(tree, (void*)&val8);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)node->value == val8);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val1);
	assert(*(int*)tree->root->right->value == val8);
	assert(*(int*)tree->root->right->left->value == val2);
	assert(*(int*)tree->root->right->right->value == val3);
	assert(*(int*)tree->root->right->right->right->value == val6);
	assert(tree->root->right->right->parent->parent == tree->root);
	free(node);

	node = removeItemFromBinarySearchTree(tree, (void*)&val4);
	assert(node == NULL);

	node = removeItemFromBinarySearchTree(tree, (void*)&val8);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)node->value == val8);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val1);
	assert(*(int*)tree->root->right->value == val3);
	assert(*(int*)tree->root->right->left->value == val2);
	assert(*(int*)tree->root->right->right->value == val6);
	assert(tree->root->right->right->parent->parent == tree->root);
	free(node);

	node = removeItemFromBinarySearchTree(tree, (void*)&val6);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(tree->root != NULL);
	assert(tree->root->parent == NULL);
	assert(tree->root->left != NULL);
	assert(tree->root->right != NULL);
	assert(*(int*)node->value == val6);
	assert(*(int*)tree->root->value == val2);
	assert(*(int*)tree->root->left->value == val1);
	assert(*(int*)tree->root->right->value == val3);
	assert(tree->root->right->left != NULL);
	assert(tree->root->right->right == NULL);
	assert(*(int*)tree->root->right->left->value == val2);
	free(node);

	freeBinarySearchTreeMemory(tree);
	free(tree);

	printf("\n");
}

// test all methods
void testAllMethods() {
	printf("test all methods.\n");

	int val1 = 1, val2 = 3, val3 = 7, val4 = 2, val5 = -3, val6 = 90, val7 = -7;
	int val8 = 4;

	BinarySearchTree* tree = createEmptyBinarySearchTree(compareIntegers);
	Node* node;

	addItemToBinarySearchTree(tree, (void*)&val1);
	addItemToBinarySearchTree(tree, (void*)&val5);
	addItemToBinarySearchTree(tree, (void*)&val7);
	addItemToBinarySearchTree(tree, (void*)&val3);
	addItemToBinarySearchTree(tree, (void*)&val2);
	addItemToBinarySearchTree(tree, (void*)&val6);

	node = getElementByValue(tree, (void*)&val8);
	assert(node == NULL);

	node = getElementByValue(tree, (void*)&val3);
	assert(node != NULL);
	assert(*(int*)node->value == val3);
	assert(node->parent == tree->root);
	assert(*(int*)node->parent->value == val1);
	assert(*(int*)node->parent->left->value == val5);
	assert(*(int*)node->parent->left->left->value == val7);
	assert(*(int*)node->left->value == val2);
	assert(*(int*)node->right->value == val6);

	node = removeItemFromBinarySearchTree(tree, (void*)&val8);
	assert(node == NULL);

	node = removeItemFromBinarySearchTree(tree, (void*)&val3);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(*(int*)node->value == val3);
	assert(*(int*)tree->root->value == val1);
	assert(*(int*)tree->root->left->value == val5);
	assert(*(int*)tree->root->left->left->value == val7);
	assert(*(int*)tree->root->right->value == val6);
	assert(*(int*)tree->root->right->left->value == val2);
	free(node);

	addItemToBinarySearchTree(tree, (void*)&val3);
	addItemToBinarySearchTree(tree, (void*)&val4);

	node = getElementByValue(tree, (void*)&val2);
	assert(node != NULL);
	assert(*(int*)node->value == val2);
	assert(node->parent->parent == tree->root);
	assert(*(int*)node->parent->parent->value == val1);
	assert(*(int*)node->parent->value == val6);
	assert(*(int*)node->parent->parent->left->value == val5);
	assert(*(int*)node->parent->parent->left->left->value == val7);
	assert(*(int*)node->left->value == val4);
	assert(*(int*)node->right->value == val3);

	node = removeItemFromBinarySearchTree(tree, (void*)&val1);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(*(int*)node->value == val1);
	assert(*(int*)tree->root->value == val4);
	assert(*(int*)tree->root->left->value == val5);
	assert(*(int*)tree->root->left->left->value == val7);
	assert(*(int*)tree->root->right->value == val6);
	assert(*(int*)tree->root->right->left->value == val2);
	assert(*(int*)tree->root->right->left->right->value == val3);
	free(node);

	node = getElementByValue(tree, (void*)&val1);
	assert(node == NULL);

	addItemToBinarySearchTree(tree, (void*)&val8);
	addItemToBinarySearchTree(tree, (void*)&val4);

	node = getElementByValue(tree, (void*)&val8);
	assert(node != NULL);
	assert(node->parent->parent->parent->parent == tree->root);
	assert(*(int*)node->value == val8);
	assert(*(int*)node->parent->value == val3);
	assert(*(int*)node->parent->parent->value == val2);
	assert(*(int*)node->parent->parent->parent->value == val6);
	assert(*(int*)node->parent->parent->left->value == val4);

	node = removeItemFromBinarySearchTree(tree, (void*)&val6);
	assert(node != NULL);
	assert(node->parent == NULL);
	assert(node->left == NULL);
	assert(node->right == NULL);
	assert(*(int*)node->value == val6);
	assert(*(int*)tree->root->value == val4);
	assert(*(int*)tree->root->left->value == val5);
	assert(*(int*)tree->root->left->left->value == val7);
	assert(*(int*)tree->root->right->value == val2);
	assert(*(int*)tree->root->right->left->value == val4);
	assert(*(int*)tree->root->right->right->value == val3);
	assert(*(int*)tree->root->right->right->left->value == val8);
	free(node);

	freeBinarySearchTreeMemory(tree);
	free(tree);

	printf("\n");
}

int main(int argc, char const *argv[]) {
	testNodeStructure();

	testCreateEmptyBinarySearchTree();

	testAddItemToBinarySearchTree();

	testFindElementByValue();

	testRemoveItemFromBinarySearchTree();

	testAllMethods();

	return 0;
}