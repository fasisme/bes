#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "stdlib.h"
#include "listM.h"
#include "listL.h"
#include "ListR.h"

using namespace std;

int main()
{
    ListM LM;
    createListM(LM);
    members data;
    string x;

    ListL LL;
    createListL(LL);
    laundrys dataL;

    ListR LR;
    createList(LR);
    createList(LR);

    int pil;
    do {
        system("cls");
        cout<<"Menu : "<<endl;
        cout<<"1. Input New Laundry"<<endl;
        cout<<"2. Input New Member"<<endl;
        cout<<"3. Input New Transaksi"<<endl;
        cout<<"4. Search Laundry"<<endl;
        cout<<"5. Search Member"<<endl;
        cout<<"6. Search Transaksi"<<endl;
        cout<<"7. Show Laundry"<<endl;
        cout<<"8. Show Member"<<endl;
        cout<<"9. Show Transaksi"<<endl;
        cout<<"10. Delete Laundry"<<endl;
        cout<<"11. Delete Member"<<endl;
        cout<<"0. Exit"<<endl;
        /*
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout<<"Tanggal: "<<ltm->tm_mday<<" "<<1 + ltm->tm_mon<<" "<<1900 + ltm->tm_year<<endl; */
        cout<<"Pilih: ";
        cin>>pil;

        switch (pil) {
        case 1: {
            system("cls");
            adrLaundry L;
            addLaundry(LL,L);
            insertLastL(LL,L);
            cout<<endl<<"Data laundry berhasil ditambahkan"<<endl<<endl;
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            adrMember M;
            addMember(LM,M);
            insertLastM(LM,M);
            cout<<endl<<"Data member berhasil ditambahkan"<<endl<<endl;
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            if (isEmpty(LL)) {
                cout<<"Data laundry tidak ada"<<endl<<endl;
            } else {
                cout<<"Daftar Laundry:"<<endl;
                int i = 1;
                adrLaundry L = first(LL);
                do {
                    cout<<i<<". "<<infoL(L).namaLaundry<<endl;
                    L = nextL(L);
                    i++;
                } while (L != first(LL));
                cout<<endl;
                newData(LR,LM,LL);
            }
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            cout<<"Cari Data Laundry"<<endl;
            cout<<"================="<<endl;
            cout<<"Nama Laundry: ";
            cin>>x;
            if (isEmpty(LL)) {
                cout<<"Belum ada data"<<endl<<endl;
            } else {
                adrLaundry L = searchL(LL,x);
                if (L == NULL) {
                    cout<<"Maaf, data tidak ditemukan"<<endl<<endl;
                } else {
                    system("cls");
                    cout<<"Data ditemukan"<<endl<<endl;
                    cout<<"Nama laundry: "<<infoL(L).namaLaundry<<endl;
                    cout<<"Harga per Kg: Rp "<<infoL(L).hargaKg<<endl;
                    cout<<"Pendapatan: Rp "<<infoL(L).pendapatan<<endl<<endl;
                }
            }
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            cout<<"Cari Data Member"<<endl;
            cout<<"================="<<endl;
            cout<<"Nama Member: ";
            cin>>x;
            if (isEmpty(LM)) {
                cout<<"Belum ada data"<<endl<<endl;
            } else {
                adrMember M = searchM(LM,x);
                if (M == NULL) {
                    cout<<"Maaf, data tidak ditemukan"<<endl;
                } else {
                    system("cls");
                    cout<<"Data ditemukan"<<endl<<endl;
                    cout<<"Nama Member: "<<infoM(M).namaMember<<endl;
                    cout<<"Membership: "<<infoM(M).membership<<endl<<endl;
                }
            }
            system("pause");
            break;
        }
        case 6: {
            system("cls");
            if (isEmpty(LR)) {
                cout<<"Belum ada transaksi"<<endl<<endl;
            } else {
                int pilih;
                cout<<"1. Search by Laundry"<<endl;
                cout<<"2. Search by Member"<<endl;
                cout<<"Pilih: ";
                cin>>pilih;
                while ((pilih != 1) && (pilih != 2)) {
                    cout<<"Pilihan salah, ulangi!"<<endl;
                    cout<<"Pilih: ";
                    cin>>pilih;
                }
                if (pilih == 1) {
                    cout<<"Nama Laundry: ";
                } else if (pilih == 2) {
                    cout<<"Nama Member: ";
                }
                cin>>x;
                cout<<endl;
                searchRel(LR,x,pilih);
            }
            system("pause");
            break;
        }
        case 7: {
            system("cls");
            cout<<"Data Laundry: "<<endl<<endl;
            printInfoL(LL);
            system("pause");
            break;
        }
        case 8: {
            system("cls");
            cout<<"Data Member: "<<endl<<endl;
            printInfoM(LM);
            system("pause");
            break;
        }
        case 9: {
            system("cls");
            cout<<"Data Transaksi: "<<endl<<endl;
            printInfoR(LR);
            system("pause");
            break;
        }
        case 10: {
            system("cls");
            if (isEmpty(LL)) {
                cout<<"Data laundry tidak ada"<<endl<<endl;
            } else {
                cout<<"Masukkan Nama Laundry yang Akan Dihapus : ";
                cin>>x;
                cout<<endl;
                //adrLaundry Q = first(LL);
                adrLaundry L = searchL(LL,x);
                if ( L == NULL )
                {
                    cout<<"Laundry Tidak Ditemukan"<<endl<<endl;
                } else {
                    //cout<<"Trans: "<<infoL(L).trans<<endl<<endl;
                    adrRel P = first(LR);
                    int i = 0;
                    while (i != infoL(L).trans) {
                        if (parent(P) == L) {
                            i++;
                            infoM(child(P)).transM--;
                            adrRel Q = P;
                            P = nextR(Q);
                            deleterelasi(LR,Q);
                            //cout<<"Berhasil delete "<<i<<endl;
                        }
                        P = nextR(P);
                    }
                    deleteL(LL,L);
                }
            }

            system("pause");
            break;
        }
        case 11: {
            system("cls");
            if (isEmpty(LM)) {
                cout<<"Data member tidak ada"<<endl<<endl;
            } else {
                cout<<"Masukkan Nama Member yang Akan Dihapus : ";
                cin>>x;
                cout<<endl;
                //adrLaundry Q = first(LL);
                adrMember M = searchM(LM,x);
                if ( M == NULL )
                {
                    cout<<"Member Tidak Ditemukan"<<endl<<endl;
                } else {
                    //cout<<"Trans: "<<infoL(L).trans<<endl<<endl;
                    adrRel P = first(LR);
                    int i = 0;
                    while (i != infoM(M).transM) {
                        if (child(P) == M) {
                            i++;
                            infoL(parent(P)).trans--;
                            adrRel Q = P;
                            P = nextR(Q);
                            //cout<<"delete "<<i<<", "<<infoM(M).transM<<endl<<endl;
                            deleterelasi(LR,Q);
                            //cout<<"Berhasil delete "<<i<<endl;
                        }
                        P = nextR(P);
                    }
                    deleteM(LM,M);
                }
            }

            system("pause");
            break;
        }
        default:
            break;
        }
    } while (pil != 0);

    return 0;
}
