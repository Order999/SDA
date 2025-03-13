#ifndef header_h
#define header_h
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
	
void insertFirst(address *First, int value);
void insertLast(address First, int value);
void insertAfter(address *First, int value);
void deleteFirst(address *First);
void deleteLast(address *First);
void deleteByValue(address *First, int value);
void printSemuaNode(address First);


#endif


