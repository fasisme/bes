#include <iostream>
#include "listM.h"

using namespace std;

void createListM(ListM &L) {
    first(L) = NULL;
}

adrMember alokasiM(members data) {
    adrMember P = new elmtListM;
    infoM(P) = data;
    nextM(P) = NULL;
    return P;
}

bool isEmpty(ListM L) {
    return first(L) == NULL;
}

void insertLastM(ListM &L, adrMember P) {
    if (isEmpty(L)) {
        first(L) = P;
        nextM(P) = P;
    } else {
        adrMember Q = first(L);
        while (nextM(Q) != first(L)) {
            Q = nextM(Q);
        }
        nextM(P) = first(L);
        nextM(Q) = P;
    }
}

void deleteM(ListM &L, adrMember &Q) {
    //Q = alamat elemen yg akan dihapus
    if (!(isEmpty(L))) {
        if (Q != NULL) {
            if (Q == first(L)) { //jika Q elemen pertama
                if (nextM(Q) == Q) { //jika isi list hanya 1
                    //P = Q;
                    first(L) = NULL;
                    nextM(Q) = NULL;
                } else { //jika isi list lebih dari 1
                    adrMember prec = first(L);
                    while (nextM(prec) != Q) {
                        prec = nextM(prec);
                    }
                    //P = Q;
                    first(L) = nextM(Q);
                    nextM(Q) = NULL;
                    nextM(prec) = first(L);
                }
            } else { //jika Q elemen terakhir/ di tengah
                adrMember prec = first(L);
                while (nextM(prec) != Q) {
                    prec = nextM(prec);
                }
                //P = Q;
                nextM(prec) = nextM(Q);
                nextM(Q) = NULL;
            }
            delete Q;
        } else {
            //jika alamat yg akan dihapus tidak ditemukan
            cout<<"not found"<<endl;
        }
    }
}

adrMember searchM(ListM L, string data) {
    if (!(isEmpty(L))) {
        adrMember P = first(L);
        while ((nextM(P) != first(L)) && (infoM(P).namaMember != data)) {
            P = nextM(P);
        }
        if (infoM(P).namaMember == data) {
            //jika data ditemukan
            return P;
        } else {
            //jika data tidak ditemukan
            return NULL;
        }
    } else {
        return NULL;
    }
}

void printInfoM(ListM &L) {
    if (!(isEmpty(L))) {
        adrMember P = first(L);
        int i = 1;
        do {
            cout<<i<<". "<<"Nama Member: "<<infoM(P).namaMember<<endl;
            cout<<"   "<<"Membership: "<<infoM(P).membership<<endl;
            cout<<"   "<<"Trans: "<<infoM(P).transM<<endl<<endl;
            P = nextM(P);
            i++;
        } while (P != first(L));
        cout<<endl;
    } else {
        cout<<"Data tidak ada"<<endl;
    }
}

void addMember(ListM &L, adrMember &M) {
    members data;

    cout<<"Input Member"<<endl;
    cout<<"============"<<endl;
    cout<<"Nama Member: ";
    cin>>data.namaMember;
    do {
        cout<<"Membership: ";
        cin>>data.membership;
        if (!(Membership(data.membership))) {
            cout<<"Membership 'A' atau 'B' atau 'C'"<<endl;
        }
    } while (!(Membership(data.membership)));
    data.transM = 0;
    M = alokasiM(data);
}

bool Membership(char x) {
    return (x == 'a') || (x == 'A') || (x == 'b') || (x == 'B') || (x == 'c') || (x == 'C');
}
