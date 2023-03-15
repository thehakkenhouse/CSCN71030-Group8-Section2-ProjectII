// RPS Pro: memory.h
// Contains the definitions of utility functions for
// safe memory management in C

#ifndef RPS_PRO_GAME_MEMORY_H
#define RPS_PRO_GAME_MEMORY_H

#include <stdbool.h>

void* tryToGetAndAssignMemorySafely(size_t, bool*);

#endif
