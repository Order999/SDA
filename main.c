#include "header.h"


int main() {
	address First, temp;
	First = Nil;
	temp = Nil;
	
	// masukan bilangan 7 sebagai elemen pertama {insert first}
	insertFirst(&First,7);
	printSemuaNode(First);
	
	// masukan bilangan 11 sebagai elemen kedua {insert last}
	insertLast(First,11);
	printSemuaNode(First);
	
	// masukan bilangan 9 diantara bilangan 7 dan 11 {insert after}
	insertAfter(&First,9);
	printSemuaNode(First);
	
	// masukan bilangan 5 di awal list {insert first}
	insertFirst(&First,5);
	printSemuaNode(First);
	
	// masukan bilangan 13 di akhir list {insert last}
	insertLast(First,13);
	printSemuaNode(First);
	
	// hapus elemen terakhir (bilangan 13) pada list {delete last}
	deleteLast(&First);
	printSemuaNode(First);
	
	// hapus bilangan 7 pada list
	deleteByValue(&First,7);
	printSemuaNode(First);
	
	// hapus elemen pertama (bilangan 5) pada list {delete first}
	deleteFirst(&First);
	printSemuaNode(First);
	
	// hapus semua elemen list deret bilangan ganjil
	while(First != Nil){
		temp = next(First);
		First = temp;
	}
	printSemuaNode(First);
	
	return 0;
}
