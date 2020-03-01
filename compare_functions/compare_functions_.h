#ifndef COMPARE_FUNCTIONS__H
#define COMPARE_FUNCTIONS__H

#include <string.h>

int compareStrings(void* arg1, void* arg2) {
	char* a = (char*)arg1;
	char* b = (char*)arg2;

	return strcmp(a, b);
}

int compareIntegers(void* arg1, void* arg2) {
	int a = *(int*)arg1;
	int b = *(int*)arg2;

	return a - b;
}

#endif // COMPARE_FUNCTIONS__H