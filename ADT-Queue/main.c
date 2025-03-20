/*Deskripsi Program*/
// Dibuat oleh
// Nama		: Ivan Setiawan Ihsan
// NIM		: 241524012
// Kelas	: 1-A D4 Teknik Informatika
// Dibuat pada : 20 Maret 2025 

#include "header.h"
#include "Tampilan.h"

int main(){
	
	Teller A, B, C;
	int antrian = 1, pilihan;
	init(&A); init(&B); init(&C);
	
	do{
		printf("\n");
		printf("\n=== SISTEM ANTRIAN BANK ===\n");
	    printf("1. Ambil Antrian\n");
	    printf("2. Proses Antrian\n");
	    printf("3. Lihat Antrian\n");
	    printf("4. Keluar\n");
	    printf("Pilihan Anda: ");
	    scanf("%d",&pilihan);
	    
	    switch(pilihan){
	    	case 1:
	    		queue(&A, &B, &C, &antrian);
	    		break;
	    	case 2:
	    		subMenu(&A, &B, &C);
	    		break;
	    	case 3:
	    		printAntrian(A,B,C);
	    		break;
	    	case 4:
	    		break;
	    	default:
	    		printf("\nPilihan tidak valid!\n");
		}
	    	
	}while(pilihan != 4);
	
	return 0;
}




