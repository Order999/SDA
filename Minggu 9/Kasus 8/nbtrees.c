#include "nbtrees.h"

void initArray(Isi_Tree P){
	
	int i;
	for(i = 0; i <= jml_maks+1; i++){
		P[i].info = '\0';
        P[i].ps_fs = nil;
        P[i].ps_nb = nil;
        P[i].ps_pr = nil;
	}
		
}

void Create_tree(Isi_Tree P){

	P[1].info = 'A'; P[1].ps_fs = 2; P[1].ps_nb = 0; P[1].ps_pr = 0;
    P[2].info = 'B'; P[2].ps_fs = 4; P[2].ps_nb = 3; P[2].ps_pr = 1;
    P[3].info = 'C'; P[3].ps_fs = 6; P[3].ps_nb = 0; P[3].ps_pr = 1;
    P[4].info = 'D'; P[4].ps_fs = 0; P[4].ps_nb = 5; P[4].ps_pr = 2;
    P[5].info = 'E'; P[5].ps_fs = 9; P[5].ps_nb = 0; P[5].ps_pr = 2;
    P[6].info = 'F'; P[6].ps_fs = 0; P[6].ps_nb = 7; P[6].ps_pr = 3;
    P[7].info = 'G'; P[7].ps_fs = 0; P[7].ps_nb = 8; P[7].ps_pr = 3;
    P[8].info = 'H'; P[8].ps_fs = 0; P[8].ps_nb = 0; P[8].ps_pr = 3;
    P[9].info = 'I'; P[9].ps_fs = 0; P[9].ps_nb = 10; P[9].ps_pr = 5;
    P[10].info = 'J'; P[10].ps_fs = 0; P[10].ps_nb = 0; P[10].ps_pr = 5;

}

bool IsEmpty(Isi_Tree P){
    return P[1].info == '\0';
}

void RekursifPreOrder(Isi_Tree P, int idx){
    
    if(idx != nil){
        printf("%c ", P[idx].info);
        int anak = P[idx].ps_fs;
        while(anak != nil){
            RekursifPreOrder(P, anak);
            anak = P[anak].ps_nb;
        }
    }

}

void PreOrder(Isi_Tree P){

    printf("Pre Order: ");
    if(!IsEmpty(P)){
        RekursifPreOrder(P, 1);
    }

}

void RekursifPostOrder(Isi_Tree P, int idx){

    if(idx != nil){
        int anak = P[idx].ps_fs;
        while(anak != nil){
            RekursifPostOrder(P, anak);
            anak = P[anak].ps_nb;
        }
        printf("%c ", P[idx].info);
    }

}

void PostOrder(Isi_Tree P){

    printf("Post Order: ");
    if(!IsEmpty(P)){
        RekursifPostOrder(P, 1);
    }

}

void RekursifInOrder(Isi_Tree P, int idx){

    if(idx != nil){
        int anak = P[idx].ps_fs;

        if(anak != nil){
            RekursifInOrder(P, anak);

            printf("%c ", P[idx].info);

            anak = P[anak].ps_nb;
            while(anak != nil){
                RekursifInOrder(P, anak);
                anak = P[anak].ps_nb;
            }
        } else {
            printf("%c ", P[idx].info);
        }
    }

}

void InOrder(Isi_Tree P){
    
    printf("In Order: ");
    if(!IsEmpty(P)){
        RekursifInOrder(P, 1);
    }

}

void LevelOrder(Isi_Tree P){
    
    int i;
    printf("Level Order: ");
    if(!IsEmpty(P)){
        for(i = 1; i <= jml_maks; i++){
	        if(P[i].info != '\0'){
	            printf("%c ", P[i].info);
	        }
        }
    }
    
}

void PrintTree(Isi_Tree P) {

    printf("Seluruh Node pada Non-Binary Tree:\n\n");
    int i;
    for(i = 1; i <= 8; i++){
        printf("--> Indeks ke-%d\n", i);
        printf("--------------------------------------------------\n");
        printf("info array ke-%d        : %c\n", i, P[i].info);
        printf("first son array ke-%d   : %d\n", i, P[i].ps_fs);
        printf("next brother array ke-%d: %d\n", i, P[i].ps_nb);
        printf("parent array ke-%d      : %d\n", i, P[i].ps_pr);
        printf("--------------------------------------------------\n\n");
    }
    
}

bool Search(Isi_Tree P, infotype x){

    int i;
    for(i = 1; i <= jml_maks; i++){
        if(P[i].info == x){
            return true;
        }
    }
    return false;

}

int nbElmt(Isi_Tree P){
    
    int jumlah = 0;
    if(!IsEmpty(P)){
        int i;
        for(i = 1; i <= jml_maks; i++){
            if(P[i].info != '\0'){
                jumlah++;
            }
        }
    }
    return jumlah;

}

int nbDaun(Isi_Tree P){

    int jumlah = 0;
    if(!IsEmpty(P)){
        int i;
        for(i = 1; i <= jml_maks; i++){
            if(P[i].info != '\0' && P[i].ps_fs == nil){
                jumlah++;
            }
        }
    }
    return jumlah;

}

int Level(Isi_Tree P, infotype x){

    int i;
    for(i = 1; i <= jml_maks; i++){
        if(P[i].info == x){
            int level = 0;
            int parent = P[i].ps_pr;
            while(parent != nil){
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;

}

int Depth(Isi_Tree P){

    int depth = 0;
    if(!IsEmpty(P) && P[1].ps_fs != nil){
        depth = RekursifDepth(P, 1);
    }
    if(depth == -1){
    	return 0;
	}
    return depth-1;

}

int RekursifDepth(Isi_Tree P, int idx){

    if(idx == nil){
        return 0;
    }
    
    int maksDepth = 0;
    int anak = P[idx].ps_fs;
    while(anak != nil){
        int anakDepth = RekursifDepth(P, anak);
        maksDepth = Max(anakDepth, maksDepth);
        anak = P[anak].ps_nb;
    }
    return maksDepth+1;

}

bool CompareTree(Isi_Tree P1, Isi_Tree P2){
	
    int i;
    for(i = 1; i <= jml_maks; i++){
        if(P1[i].info != P2[i].info ||
            P1[i].ps_fs != P2[i].ps_fs ||
            P1[i].ps_nb != P2[i].ps_nb ||
            P1[i].ps_pr != P2[i].ps_pr){
                return false;
            }
    }
    return true;

}

int Max(int a, int b){

    return (a > b) ? a : b;

}
