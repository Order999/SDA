#include "nbtrees.h"

int main(){
	
    Isi_Tree T;
    initArray(T);
    int jumlahNode;

    printf("Masukkan jumlah node (maks %d): ", jml_maks);
    scanf("%d", &jumlahNode);
    getchar();

    if (jumlahNode < 1 || jumlahNode > jml_maks) {
        printf("Jumlah node tidak valid.\n");
        return 1;
    }

    printf("\n=== Input Tree ===\n");
    Create_tree(T, jumlahNode);

    printf("\n=== Traversal Tree ===\n");
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    LevelOrder(T);
    printf("\n");

    printf("\n=== Struktur Tree (PrintTree) ===\n");
    PrintTree(T, 1, 0);

    printf("\n=== Informasi Tree ===\n");
    printf("Jumlah elemen (nbElmt): %d\n", nbElmt(T));
    printf("Jumlah daun (nbDaun): %d\n", nbDaun(T));
    printf("Depth pohon: %d\n", Depth(T));

    infotype cari;
    printf("\nMasukkan karakter yang ingin dicari levelnya: ");
    scanf(" %c", &cari);
    if (Search(T, cari)) {
        printf("Karakter '%c' ditemukan di level %d.\n", cari, Level(T, cari));
    } else {
        printf("Karakter '%c' tidak ditemukan dalam tree.\n", cari);
    }

    return 0;
}
