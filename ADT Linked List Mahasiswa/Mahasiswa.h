#ifndef header_h
#define header_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define nama(P) (P)->nama
#define nilai(P) (P)->nilai
#define next(P) (P)->next
#define First(L) (L).First
#define Nil NULL

typedef struct tElmtlist *address;
typedef struct tElmtlist {
    char nama[50];
    int nilai;
    address next;
} ElmtList;

typedef struct {
	address First;
}List;

void createElement(List *L1, List *duplicate, char nama[], int nilai);
char* getNama(address P);
int getNilai(address P);
void deleteElement(address P);
bool isEmptyElement(address P);
void createList(List *L);
void deleteList(List *L);
bool isEmptyList(List L);
int countElement(List L);
void copyElement(List *L1, List *L2);
void deleteDuplicate(List *L2, List *duplicate);
void printList(List L);

#endif	
