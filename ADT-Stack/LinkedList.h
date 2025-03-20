#ifndef Linkedlist_h
#define Linkedlist_h
#include <stdio.h>
#include <stdlib.h>
#define info(First) (First)->info
#define next(First) (First)->next
#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

// Definisi struct baru,karena file LinkedList.h kemarin tidak ada struct untuk pointer ke node paling awal, hanya memakai address First.
typedef struct {
	address top;
}Stack;
	
void insertFirst(address *First, int value);
void insertLast(address First, int value);
void insertAfter(address *First, int value);
void deleteFirst(address *First);
void deleteLast(address *First);
void deleteByValue(address *First, int value);
void printSemuaNode(address First);


#endif


