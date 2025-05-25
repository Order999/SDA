/* Program ini dibuat oleh:
Nama         : Ivan Setiawan Ihsan
NIM          : 241524012
Kelas        : 1-A/D4 Teknik Informatika
Dibuat pada  : 17 Mei 2025
*/

#ifndef nbtrees_h
#define nbtrees_h

#include <stdio.h>
#include <stdbool.h>

#define jml_maks 20
#define kebawah  1
#define keatas   2
#define kekanan  3
#define nil 0

typedef char infotype;
typedef int address;

typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

// Fungsi dan Prosedur Utama
void initArray(Isi_Tree P);
void Create_tree(Isi_Tree P, int Jml_Node);

bool IsEmpty(Isi_Tree P);

void PreOrder(Isi_Tree P);
void InOrder(Isi_Tree P);
void PostOrder(Isi_Tree P);
void LevelOrder(Isi_Tree P);
void PrintTree(Isi_Tree P, int root, int level);

bool Search(Isi_Tree P, infotype x);

int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype x);
int Depth(Isi_Tree P);
int Max(int a, int b);

#endif
