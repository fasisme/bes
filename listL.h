#include <iostream>
#ifndef LISTL_H_INCLUDED
#define LISTL_H_INCLUDED
#define infoL(P) P->infoL
#define nextL(P) P->nextL
#define first(L) L.first

using namespace std;

typedef struct elmtListL *adrLaundry;

struct laundrys {
    string namaLaundry;
    int hargaKg,pendapatan,trans;
};

struct elmtListL {
    laundrys infoL;
    adrLaundry nextL;
};

struct ListL {
    adrLaundry first;
};

void createListL(ListL &L);
adrLaundry alokasiL(laundrys data);
void insertLastL(ListL &L, adrLaundry P);
bool isEmpty(ListL L);
void deleteL(ListL &L, adrLaundry &Q);
adrLaundry searchL(ListL L, string data);
void printInfoL(ListL &L);
void addLaundry(ListL &LL, adrLaundry &L);
adrLaundry findLast(ListL L);

#endif // LISTL_H_INCLUDED
