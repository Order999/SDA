/*Identitas*/
// Program ini dibuat oleh:
// Nama 	: Ivan Setiawan Ihsan
// NIM 		: 241524012
// Kelas	: 1-A D4 Teknik Informatika
// Tanggal	: 20 Maret 2025 

#include "header.h"



int main(int argc, char *argv[]) {
	
	Stack stack;
	top(stack) = Nil;
	
	int bilangan;
	int hasil;
	int sisa;
	char lanjut = 'y';
	
	while(lanjut == 'y'){	
		system("cls");
		printf("Masukkan bilangan yang ingin diubah ke biner : ");
		scanf("%d",&bilangan);
		getchar();
		
		while(bilangan != 0){
			hasil = bilangan/2;
			sisa = bilangan - (hasil*2);
			bilangan = hasil;
			push(&stack, sisa);
		}
		
		printf("Hasil Konversi: ");
		
		while(top(stack) != Nil){
			printf("%d",pop(&stack));
		}
		
		printf("\n\nApakah anda ingin melanjutkan? (y/t)");
		lanjut = getchar();
	}
	return 0;
}
