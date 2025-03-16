#include "Mahasiswa.h"

int main() {
	List L1, L2, duplicate;
	createList(&L1);
	createList(&L2);
	createList(&duplicate);
	
	createElement(&L1, &duplicate, "Joko", 85);
	createElement(&L1, &duplicate, "Budi", 73);
	createElement(&L1, &duplicate, "Joko", 86);
	createElement(&L1, &duplicate, "Andi", 75);
	createElement(&L1, &duplicate, "Bagas", 85);
	createElement(&L1, &duplicate, "Asep", 70);
	printf("Isi List L1\n");
	printList(L1);
	copyElement(&L1, &L2);
	printf("\nIsi List L2\n");
	printList(L2);
	deleteDuplicate(&L2, &duplicate);
	printf("\nIsi List L2 setelah menghapus element duplikat\n");
	printList(L2);
	printf("\nIsi List duplicate\n");
	printList(duplicate);
	
	deleteList(&L1);
	deleteList(&L2);
	deleteList(&duplicate);
	
	printf("\nIsi List L1 setelah dihapus\n");
	printList(L1);
	printf("\nIsi List L2 setelah dihapus\n");
	printList(L2);
	return 0;
}
