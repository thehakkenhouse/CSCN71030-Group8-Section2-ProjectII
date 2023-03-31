// RPS Pro: memory.c
// Contains the implementations of utility functions
// related to safe memory management in C

#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MEMORY_ERROR_MESSAGE "\nERROR: Memory could not be allocated for RPS Pro. Please consider restarting your system. The program will now quit.\n"
#define MEMORY_ERROR_CODE 1

void* tryToGetAndAssignMemorySafely(size_t sizeOfMemory) {
	// First, we'll call malloc to try to get a new memory pointer
	void* possiblePointer = malloc(sizeOfMemory);

	// Then, we'll see if this pointer is null; if it is, we'll
	// quit the program gracefully to prevent crashes
	if(!possiblePointer)
	{
		printf(MEMORY_ERROR_MESSAGE);
		exit(MEMORY_ERROR_CODE);
	}

	// Otherwise, we have a valid pointer
	return possiblePointer;
}
