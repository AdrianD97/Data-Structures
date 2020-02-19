#ifndef COMPARE_FUNCTIONS_H
#define COMPARE_FUNCTIONS_H

#include <string.h>

unsigned int compareStrings(void* arg1, void* arg2) {
	char* a = (char*)arg1;
	char* b = (char*)arg2;

	return (strcmp(a, b) == 0) ? 1 : 0;
}

unsigned int compareIntegers(void* arg1, void* arg2) {
	int a = *(int*)arg1;
	int b = *(int*)arg2;

	return (a == b) ? 1 : 0;
}

unsigned int compareChars(void* arg1, void* arg2) {
	char a = *(char*)arg1;
	char b = *(char*)arg2;

	return (a == b) ? 1 : 0;
}

#endif // COMPARE_FUNCTIONS_H