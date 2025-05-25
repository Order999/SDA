#include "nbtrees.h"

void initArray(Isi_Tree P){
	
	int i;
	for(i = 0; i <= jml_maks+1; i++){
		P[i].info = '\0';
	}
		
}

void Create_tree(Isi_Tree P, int Jml_Node){

    int i;
    
    for(i = 1; i <=  Jml_Node && i <= jml_maks; i++){
        printf("Masukkan info dari node ke-%d: ", i);
        fflush(stdin);
        scanf("%c", &(P[i].info));
        P[i].ps_fs = nil;
        P[i].ps_nb = nil;
        P[i].ps_pr = nil;
    }

    int jmlAnak;
    for(i = 1; i <= Jml_Node && i <= jml_maks; i++){
        printf("Masukkan jumlah anak dari node %c: ", P[i].info);
        scanf("%d", &jmlAnak);
        getchar();
        int j, idx, last;
        for(j = 1; j <= jmlAnak; j++){
            printf("Masukkan indeks anak ke-%d dari node %c: ", j, P[i].info);
            scanf("%d", &idx);
            getchar();
            P[idx].ps_pr = i;
            if(j == 1){
                P[i].ps_fs = idx;
            }else{
                P[last].ps_nb = idx;   
            }
            last = idx;
        }
    }
    
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

void PrintTree(Isi_Tree P, int root, int level) {

    if (root != 0) {
        int i;
        for (i = 0; i < level; i++) printf("  ");
        printf("%c\n", P[root].info);
        int child = P[root].ps_fs;
        while (child != 0) {
            PrintTree(P, child, level + 1);
            child = P[child].ps_nb;
        }
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

int Max(int a, int b){

    return (a > b) ? a : b;

}
