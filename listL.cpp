#include <iostream>
#include "listL.h"

using namespace std;

void createListL(ListL &L) {
    first(L) = NULL;
}

adrLaundry alokasiL(laundrys data) {
    adrLaundry P = new elmtListL;
    infoL(P) = data;
    nextL(P) = NULL;
    return P;
}

bool isEmpty(ListL L) {
    return first(L) == NULL;
}

void insertLastL(ListL &L, adrLaundry P) {
    if (isEmpty(L)) {
        first(L) = P;
        nextL(P) = P;
    } else {
        adrLaundry Q = first(L);
        while (nextL(Q) != first(L)) {
            Q = nextL(Q);
        }
        nextL(P) = first(L);
        nextL(Q) = P;
    }
}

void deleteL(ListL &L, adrLaundry &Q) {
    //Q = alamat elemen yg akan dihapus
    if (!(isEmpty(L))) {
        if (Q != NULL) {
            if (Q == first(L)) { //jika Q elemen pertama
                if (nextL(Q) == Q) { //jika isi list hanya 1
                    //P = Q;
                    first(L) = NULL;
                    nextL(Q) = NULL;
                } else { //jika isi list lebih dari 1
                    adrLaundry prec = first(L);
                    while (nextL(prec) != Q) {
                        prec = nextL(prec);
                    }
                    //P = Q;
                    first(L) = nextL(Q);
                    nextL(Q) = NULL;
                    nextL(prec) = first(L);
                }
            } else { //jika Q elemen terakhir/ di tengah
                adrLaundry prec = first(L);
                while (nextL(prec) != Q) {
                    prec = nextL(prec);
                }
                //P = Q;
                nextL(prec) = nextL(Q);
                nextL(Q) = NULL;
            }
            delete Q;
        }
    }
}

/*
adrLaundry findLast(ListL L){
    adrLaundry P = first(L);
    while (nextL(P) != first(L)){
        P = nextL(P);
    }
    return P;
} */

adrLaundry searchL(ListL L, string data) {
    if (!(isEmpty(L))) {
        adrLaundry P = first(L);
        while ((nextL(P) != first(L)) && (infoL(P).namaLaundry != data)) {
            P = nextL(P);
        }
        if (infoL(P).namaLaundry == data) {
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

void printInfoL(ListL &L) {
    if (!(isEmpty(L))) {
        adrLaundry P = first(L);
        int i = 1;
        do {
            cout<<i<<". "<<"Nama laundry: "<<infoL(P).namaLaundry<<endl;
            cout<<"   "<<"Harga per kg: Rp "<<infoL(P).hargaKg<<endl;
            cout<<"   "<<"Pendapatan: Rp "<<infoL(P).pendapatan<<endl;
            cout<<"   "<<"Trans: Rp "<<infoL(P).trans<<endl<<endl;
            i++;
            P = nextL(P);
        } while (P != first(L));
        cout<<endl;
    } else {
        cout<<"Data tidak ada"<<endl;
    }
}

void addLaundry(ListL &LL, adrLaundry &L) {
    laundrys dataL;

    cout<<"Input Data Laundry"<<endl;
    cout<<"=================="<<endl;
    adrLaundry x;
    if (!(isEmpty(LL))) {
        do {
            cout<<"Nama Laundry: ";
            cin>>dataL.namaLaundry;
            x = searchL(LL,dataL.namaLaundry);
            if (x != NULL) {
                cout<<dataL.namaLaundry<<" sudah ada, input lagi"<<endl;
            }
        } while (x != NULL);
    } else {
        cout<<"Nama Laundry: ";
        cin>>dataL.namaLaundry;
    }
    cout<<"Harga per Kg: Rp ";
    cin>>dataL.hargaKg;
    dataL.trans = 0;
    dataL.pendapatan = 0;
    L = alokasiL(dataL);
}
