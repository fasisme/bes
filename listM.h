#include <iostream>
#ifndef LISTM_H_INCLUDED
#define LISTM_H_INCLUDED
#define infoM(P) P->infoM
#define nextM(P) P->nextM
#define first(L) L.first

using namespace std;

typedef struct elmtListM *adrMember;

struct members {
    string namaMember;
    char membership;
    int transM;
};

struct elmtListM {
    members infoM;
    adrMember nextM;
};

struct ListM {
    adrMember first;
};

void createListM(ListM &L);
adrMember alokasiM(members data);
void insertLastM(ListM &L, adrMember P);
bool isEmpty(ListM L);
void deleteM(ListM &L, adrMember &Q);
adrMember searchM(ListM L, string data);
void printInfoM(ListM &L);
void addMember(ListM &L, adrMember &M);
bool Membership(char x);

#endif // LISTM_H_INCLUDED
