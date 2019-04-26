#include <iostream>
#include <ctime>
#include <string>
#include "listL.h"
#include "listM.h"
#include "ListR.h"

using namespace std;

void createList(ListR &L) {
    first(L) = NULL;
    last(L) = NULL;
}
bool isEmpty(ListR L) {
    return first(L) == NULL;
}

/*
void dealokasi(adrRel &P){
    delete P;
} */

void deleterelasi(ListR &LR, adrRel &P)
{
    if (!(isEmpty(LR))) {
        if (P == first(LR)) {
            deleteFirst(LR,P);
        } else {
            if (P == last(LR)) {
                deleteLast(LR,P);
            } else {
                adrRel prec = first(LR);
                while (nextR(prec) != P) {
                    prec = nextR(prec);
                }
                parent(P) = NULL;
                child(P) = NULL;
                nextR(prec) = nextR(P);
                nextR(P) = NULL;
                delete P;
            }
        }
    }
}

adrRel alokasi(adrLaundry P, adrMember C, relasi data) {
    adrRel Q = new elmtListR;
    infoR(Q) = data;
    child(Q) = C;
    parent(Q) = P;
    nextR(Q) = NULL;
    return Q;
}

/*
void insertFirst(ListR &L, adrRel P){
   if(firstR(L) != NULL){
        nextR(P) = first(L);
        first(L) = P;
        lastR(L) = first(L);
    }
    else{
        firstR(L) = P;
    }

} */

void insertLast(ListR &L, adrRel P){
    adrRel Q;
    if (isEmpty(L)) {
        first(L) = P;
        last(L) = P;
        nextR(P) = P;
    } else {
        nextR(last(L)) = P;
        last(L) = P;
        nextR(P) = first(L);
    }
}

void newData(ListR &LR, ListM &LM, ListL &LL) {
    members data;
    relasi dataR;
    string findM,findL;
    adrLaundry L;

    cout<<"Nama Customer: ";
    cin>>findM;
    adrMember M = searchM(LM,findM);
    if (M == NULL) {
        data.namaMember = findM;
        data.transM = 0;
        do {
            cout<<"Membership: ";
            cin>>data.membership;
            if (!(Membership(data.membership))) {
                cout<<"Membership 'A' atau 'B' atau 'C'"<<endl;
            }
        } while (!(Membership(data.membership)));
        M = alokasiM(data);
        insertLastM(LM,M);
    }
    cout<<"Nama Laundry: ";
    cin>>findL;
    do {
        L = searchL(LL,findL);
        if (L == NULL) {
            cout<<"Laundry tidak ada, ulangi!"<<endl;
            cout<<"Nama Laundry: ";
            cin>>findL;
        }
    } while (L == NULL);
    cout<<"Berat Cucian: ";
    cin>>dataR.berat;
    int harga = infoL(L).hargaKg;
    char membership = infoM(M).membership;
    int diskon;
    if ((membership == 'A') || (membership = 'a')) {
        diskon = harga * 0.2;
    } else if ((membership == 'B') || (membership = 'b')) {
        diskon = harga * 0.15;
    } else if ((membership == 'C') || (membership = 'c')) {
        diskon = harga * 0.1;
    } else {
        diskon = 0;
    }
    infoL(L).trans++;
    infoM(M).transM++;
    /*
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int tanggal = ltm->tm_mday;
    int bln = 1 + ltm->tm_mon;
    int thn = 1900 + ltm->tm_year;
    dataR.tgl = tanggal.str(); */
    dataR.total = harga * dataR.berat - diskon;
    infoL(L).pendapatan += dataR.total;
    adrRel R = alokasi(L,M,dataR);
    insertLast(LR,R);
}

void deleteFirst(ListR &L, adrRel &P){
    if(first(L) != NULL)
    {
        if (nextR(P) == P) {
            nextR(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
        } else {
            if (nextR(P) == last(L)) {
                first(L) = last(L);
                nextR(last(L)) = first(L);
            } else {
                first(L) = nextR(P);
            }
        }
        parent(P) = NULL;
        child(P) = NULL;
        delete P;
    }
}

void deleteLast(ListR &L, adrRel &P){
    adrRel Q = first(L);
    while (nextR(Q) != last(L)) {
        Q = nextR(Q);
    }
    last(L) = Q;
    nextR(Q) = first(L);
    nextR(P) = NULL;
    parent(P) = NULL;
    child(P) = NULL;
    delete P;
}

/*
adrRel findElm(ListR L, adrLaundry P, adrMember C){
    adrRel Q = first(L);
    while(Q != first(L)){
    if(parent(Q)==P && child(Q)== C)
    {
    return Q;
    }
    Q = nextR(Q);
    }
    return NULL;
} */

void printInfoR(ListR L)
{
    if(isEmpty(L))
    {
        cout << "Data tidak ada" <<endl;
    }
    else
    {
        adrRel P = first(L);
        do
        {
            cout<<"Nama customer: "<<infoM(child(P)).namaMember<<endl;
            cout<<"Nama laundry: "<<infoL(parent(P)).namaLaundry<<endl;
            //cout<<"Tanggal: "<<infoR(P).tgl<<endl;
            cout<<"Berat cucian: "<<infoR(P).berat<<" Kg"<<endl;
            cout<<"Total harga: Rp "<<infoR(P).total<<endl<<endl;
            P=nextR(P);
        } while (P != first(L));
        cout << endl;
    }
}

void searchRel(ListR LR, string x, int pil) {
    adrRel R = first(LR);
    bool ada = false;
    if (pil == 1) {
        do {
            if (infoL(parent(R)).namaLaundry == x) {
                cout<<"Nama customer: "<<infoM(child(R)).namaMember<<endl;
                //cout<<"Nama laundry: "<<infoL(parent(R)).namaLaundry<<endl;
                //cout<<"Tanggal: "<<infoR(P).tgl<<endl;
                cout<<"Berat cucian: "<<infoR(R).berat<<" Kg"<<endl;
                cout<<"Total harga: Rp "<<infoR(R).total<<endl<<endl;
                ada = true;
            }
            R = nextR(R);
        } while (R != first(LR));
    } else {
        do {
            if (infoM(child(R)).namaMember == x) {
                //cout<<"Nama customer: "<<infoM(child(R)).namaMember<<endl;
                cout<<"Nama laundry: "<<infoL(parent(R)).namaLaundry<<endl;
                //cout<<"Tanggal: "<<infoR(P).tgl<<endl;
                cout<<"Berat cucian: "<<infoR(R).berat<<" Kg"<<endl;
                cout<<"Total harga: Rp "<<infoR(R).total<<endl<<endl;
                ada = true;
            }
            R = nextR(R);
        } while (R != first(LR));
    }
    if (ada == false) {
        if (pil == 1) {
            cout<<"Laundry "<<x<<" tidak ditemukan atau tidak ada transaksi"<<endl;
        } else {
            cout<<"Member "<<x<<" tidak ditemukan atau tidak ada transaksi"<<endl;
        }
        cout<<endl;
    }
}
