#include "nbtrees.h"

int main(){
	
    Isi_Tree T1, T2;
    initArray(T1); initArray(T2);
    Create_tree(T1); 
    int pilihan; infotype cari;
    do{
        system("cls");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);
        system("cls");
        switch(pilihan){
            case 1:
                PreOrder(T1);
                break;
            case 2:
                InOrder(T1);
                break;
            case 3:
                PostOrder(T1);
                break;
            case 4:
                LevelOrder(T1);
                break;
            case 5:
                PrintTree(T1);
                break;
            case 6:
                printf("Masukkan info dari node yang ingin dicari dalam tree: ");
                scanf(" %c", &cari);
                if(Search(T1, cari)){
                    printf("Node dengan info %c ada dalam tree\n", cari);
                }else{
                    printf("Node dengan info %c tidak ada dalam tree\n", cari);
                }
                break;
            case 7:
                printf("Jumlah daun (nbDaun): %d\n", nbDaun(T1));
                break;
            case 8:
                printf("\nMasukkan karakter yang ingin dicari levelnya: ");
                scanf(" %c", &cari);
                if (Search(T1, cari)) {
                    printf("Karakter '%c' ditemukan di level %d.\n", cari, Level(T1, cari));
                } else {
                    printf("Karakter '%c' tidak ditemukan dalam tree.\n", cari);
                }
                break;
            case 9:
                printf("Kedalaman pohon: %d\n", Depth(T1));
                break;
            case 10:
                Create_tree(T2);
                if(CompareTree(T1, T2)){
                    printf("Tree T1 dan T2 sama\n");
                }else{
                    printf("Tree T1 dan T2 beda\n");
                }
                break;
            case 11:
            	break;
            default:
                printf("pilihan tidak valid. Mohon masukkan ulang");
        }
        if(pilihan != 11){
            printf("Tekan enter untuk melanjutkan...");
            while(getchar() != '\n');
            getchar();
        }
    }while(pilihan != 11);

    return 0;
}
