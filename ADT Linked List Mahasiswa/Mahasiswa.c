#include "Mahasiswa.h"

// Constructor untuk Element dalam List 1 dan langsung diurutkan secara ascending berdasarkan nama
void createElement(List *L1, List *duplicate, char nama[], int nilai) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P == Nil) {
        printf("Memori tidak cukup\n");
        return;
    }
    strcpy(nama(P), nama);
    nilai(P) = nilai;
    next(P) = Nil;
    
    // Cek apakah nama sudah ada di L1
    address current = First(*L1);
    while (current != Nil) {
        if (strcmp(getNama(current), nama) == 0) {
            // Jika nama sudah ada, salin elemen ke duplicate
            address Q = (address) malloc(sizeof(ElmtList));
            if (Q != Nil) {
                strcpy(nama(Q), nama);
                nilai(Q) = nilai;
                next(Q) = First(*duplicate);
                First(*duplicate) = Q;
            }
            break;
        }
        current = next(current);
    }
    
    // Menambahkan elemen ke L1 secara ascending berdasarkan nama
    if (isEmptyList(*L1) || strcmp(nama, getNama(First(*L1))) < 0) {
        next(P) = First(*L1);
        First(*L1) = P;
    } else {
        current = First(*L1);
        while (next(current) != Nil && strcmp(getNama(next(current)), nama) < 0) {
            current = next(current);
        }
        next(P) = next(current);
        next(current) = P;
    }
}


// Prosedur untuk menyalin elemen dari L1 ke L2 dengan nilai lebih dari 70
void copyElement(List *L1, List *L2) {
    address current = First(*L1);
    while (current != Nil) {
        if (getNilai(current) > 70) {
            address temp = First(*L2);
            address Q = (address) malloc(sizeof(ElmtList));
            strcpy(nama(Q), getNama(current));
            nilai(Q) = getNilai(current);
            next(Q) = Nil;
                
            if (isEmptyList(*L2) || nilai(Q) >= getNilai(First(*L2))) {
                next(Q) = First(*L2);
                First(*L2) = Q;
            } else {
                address temp2 = First(*L2);
                while (next(temp2) != Nil && getNilai(next(temp2)) > nilai(Q)) {
                    temp2 = next(temp2);
                }
                next(Q) = next(temp2);
                next(temp2) = Q;
            }
        }
        current = next(current);
    }
}

// Prosedur untuk menghapus elemen dari L2 yang ada di duplicate
void deleteDuplicate(List *L2, List *duplicate) {
    address prev = Nil, current = First(*L2);
    while (current != Nil) {
        address check = First(*duplicate);
        bool found = false;
        while (check != Nil) {
            if (strcmp(getNama(current), getNama(check)) == 0 && getNilai(current) == getNilai(check)) {
                found = true;
                break;
            }
            check = next(check);
        }
        
        if (found) {
            if (prev == Nil) {
                First(*L2) = next(current);
                deleteElement(current);
                current = First(*L2);
            } else {
                next(prev) = next(current);
                deleteElement(current);
                current = next(prev);
            }
        } else {
            prev = current;
            current = next(current);
        }
    }
}

// Getter untuk subvar nama pada ElmtList
char* getNama(address P) {
    return nama(P);
}

// Getter untuk subvar nilai pada ElmtList
int getNilai(address P) {
    return nilai(P);
}

// Destructor untuk ElmtList
void deleteElement(address P) {
    if (P != Nil) {
        free(P);
    }
}

// Validator untuk ElmtList
bool isEmptyElement(address P) {
    return P == Nil;
}

// Constructor untuk List
void createList(List *L) {
    First(*L) = Nil;
}

// Destructor untuk List
void deleteList(List *L) {
    address current = First(*L);
    while (current != Nil) {
        address temp = current;
		current = next(current);
		deleteElement(temp);
    }
    First(*L) = Nil;
}

// Validator untuk List
bool isEmptyList(List L) {
    return First(L) == Nil;
}

// Menghitung jumlah ElmtList dalam List
int countElement(List L) {
    int count = 0;
    address current = First(L);
    while (current != Nil) {
        count++;
        current = next(current);
    }
    return count;
}

// Menampilkan setiap ElmtList dalam List
void printList(List L) {
    address current = First(L);
    int count = 0;
    if (isEmptyList(L)) {
        printf("List kosong.\n");
        return;
    }
    while (current != Nil) {
        count++;
        printf("%d. %s, Nilai: %d\n", count, getNama(current), getNilai(current));
        current = next(current);
    }
}
