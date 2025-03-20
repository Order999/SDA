#ifndef header_h
#define header_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#define top(S) (S).top
#define Nil NULL

void push(Stack *stack, int sisa);
int pop(Stack *stack);

#endif
