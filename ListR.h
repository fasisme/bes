#include <iostream>
#ifndef LISTR_H_INCLUDED
#define LISTR_H_INCLUDED
#define first(L) L.first
#define nextR(P) P->nextR
#define last(L) L.last
#define infoR(P) P->infoR
#define child(P) P->child
#define parent(P) P->parent
#include "listL.h"
#include "listM.h"

using namespace std;

typedef struct elmtListR *adrRel;

struct relasi {
    int berat, total;
    //string tgl;
};

struct elmtListR {
    relasi infoR;
    adrRel nextR;
    adrLaundry parent;
    adrMember child;
};

struct ListR {
//* PAKAI LAST
    adrRel first;
    adrRel last;
};


void createList(ListR &L);
bool isEmpty(ListR L);
void insertFirst(ListR &L, adrRel P);
void insertLast(ListR &L, adrRel P);
void deleteFirst(ListR &L, adrRel &P);
void deleteLast(ListR &L, adrRel &P);
void deleterelasi(ListR &LR, adrRel &P);
void newData(ListR &LR, ListM &LM, ListL &LL);


adrRel alokasi(adrLaundry P, adrMember C, relasi data);
void dealokasi(adrRel &P);
adrRel findElm(ListR L, adrLaundry P, adrMember C);
void printInfoR(ListR LR);
void searchRel(ListR LR, string x, int pil);
#endif // LISTR_H_INCLUDED
