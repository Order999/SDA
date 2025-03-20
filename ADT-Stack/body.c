#include "header.h"

// Prosedur yang digunakan untuk membuat node baru dengan value info sisa dari pembagian bilangan desimal dengan 2 menggunakan struktur data stack
void push(Stack *stack, int sisa){
	
	insertFirst(&(stack->top), sisa);

}

// Prosedur yang digunakan mengolah data teratas pada struktur data stack
int pop(Stack *stack){
	
	int biner = info(stack->top);
	deleteFirst(&(stack->top));
	return biner;
	
}
