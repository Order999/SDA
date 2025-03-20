#include "Tampilan.h"


// Prosedur untuk menampilkan subMenu untuk menu Proses antrian
void subMenu(Teller *A, Teller *B, Teller *C){
	int pilihan;
	do{
		printf("1. Proses Teller A\n");
		printf("2. Proses Teller B\n");
		printf("3. Proses Teller C\n");
		printf("4. Kembali\n");
		printf("Pilihan anda : ");
		scanf("%d",&pilihan);
		
		switch(pilihan){
	    	case 1:
	    		dequeue(A);
	    		printAntrian(*A, *B, *C);
	    		break;
	    	case 2:
	    		dequeue(B);
	    		printAntrian(*A, *B, *C);
	    		break;
	    	case 3:
	    		dequeue(C);
	    		printAntrian(*A, *B, *C);
	    		break;
	    	case 4:
	    		break;
	    	default:
	    		printf("\nPilihan tidak valid!\n");
		}
	}while(pilihan != 4);
}

// Prosedur menampilkan antrian yang ada pada setiap teller
void printAntrian(Teller A, Teller B, Teller C){
	printf("Antrian Teller A: ");
	printSemuaNode(first(A));
	printf("\n");
	printf("Antrian Teller B: ");
	printSemuaNode(first(B));
	printf("\n");
	printf("Antrian Teller C: ");
	printSemuaNode(first(C));
}
