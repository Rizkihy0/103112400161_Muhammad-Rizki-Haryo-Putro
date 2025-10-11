# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori


### A. <br/>


### B. <br/>


### c. <br/>



## Guided 

### 1. Struct

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMHS(mahasiswa &m) {
    cout << "masukkan nama mahasiswa:";
    cin >> m.nama;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2)/2;

}

int main() {
    mahasiswa mhs;

    inputMHS(mhs);
    cout << "Rata - rata nilai adalah : " << rata2(mhs) << endl;

    system("pause");
    return 0;
}
```
Program di atas berfungsi untuk menginput nama dan dua nilai mahasiswa, lalu menghitung rata-rata nilainya.

### 2. Single Linked List

```C++
#include <iostream>
using namespace std;

struct node{
    float data;
    node* next;

}; 

struct list{
    node* first;

};

void buatList(list &L){
    L.first = NULL;
    
}

node* buatElemen(float X){
    node* elm = new node;
    elm -> data = X;
    elm -> next = NULL;
    return elm;
}
void insertAscending( list &L, node* elm){
    if (L.first == NULL || elm -> data < L.first -> data ){
        elm -> next = L.first;
        L.first = elm;

    }
    else{
        node* before = L.first;
        node* after = L.first -> next;
        while(after != NULL && elm -> data > after -> data){
            before = after;
            after = after -> next;
        }
        elm -> next = after;
        before -> next = elm;
    }
}

void tampilList(list L){
    node* p = L.first;
    while(p != NULL){
        cout << p -> data << " -> ";
        p = p -> next;
    }
    cout << "NULL " << endl;
}

int main(){
    list L;
    buatList(L);

    node* satu = buatElemen(10.5);
    node* dua = buatElemen(12.0);
    node* tiga =  buatElemen(20.9);
    node* empat = buatElemen(25.1);

    satu -> next = dua;
    dua -> next = tiga;
    tiga -> next = empat;

    L.first = satu;
    
    cout << "isi list : " << endl;
    tampilList(L);

    float X;
    cout << "Masukan nilai : ";
    cin >>  X;

    node* elm = buatElemen(X);
    insertAscending(L, elm );
    cout << "List setelah ditambah : " << endl;
    tampilList(L);
    return 0;
}
 ```
Program ini membuat linked list berisi data bertipe float, lalu menambahkan elemen baru secara berurutan (ascending) berdasarkan nilainya.

### 3. 

```C++

```
Program mencari nilai maksimum dan menghitung hasil aritmatika array dengan prosedur

## Unguided 

### 1. 

```C++
#include <iostream>
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    string nama, nim;
    float uts, uas, tugas;
    int n;

    cout << "Jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNama: "; cin >> nama;
        cout << "NIM : "; cin >> nim;
        cout << "UTS : "; cin >> uts;
        cout << "UAS : "; cin >> uas;
        cout << "Tugas: "; cin >> tugas;

        cout << "Nilai Akhir: " << hitungNilaiAkhir(uts, uas, tugas) << endl;
    }
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu3_modul3/output-unguided1-modul3.png)

Program ini digunakan untuk menghitung nilai akhir beberapa mahasiswa berdasarkan nilai UTS, UAS, dan Tugas dengan bobot tertentu.

### 2. 

file: pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
using namespace std;

typedef struct {
    string namaPel;
    string kodePel;
} pelajaran;

pelajaran create_pelajaran(string nama, string kode);

void tampil_pelajaran(pelajaran p);

#endif
```

file: pelajaran.cpp
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string nama, string kode) {
    pelajaran p;
    p.namaPel = nama;
    p.kodePel = kode;
    return p;
}

void tampil_pelajaran(pelajaran p) {
    cout << "Nama Pelajaran : " << p.namaPel << endl;
    cout << "Kode Pelajaran : " << p.kodePel << endl;
}
```

file: main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel, kodePel;

    cout << "Masukkan nama pelajaran : ";
    getline(cin, namaPel);
    cout << "Masukkan kode pelajaran : ";
    cin >> kodePel;

    pelajaran p = create_pelajaran(namaPel, kodePel);

    cout << "\nData Pelajaran:\n";
    tampil_pelajaran(p);

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu3_modul3/output-unguided2-modul3.png)

Program ini digunakan untuk membuat dan menampilkan data pelajaran yang berisi nama pelajaran dan kode pelajaran, menggunakan file header (.h), file implementasi (.cpp), dan file utama (main.cpp).

### 3. 

```C++
#include <iostream>
using namespace std;

struct Pelajaran {
    string namaPel;
    string kodePel;
};

Pelajaran createPelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaPel = nama;
    p.kodePel = kode;
    return p;
}

void tampilPelajaran(Pelajaran p) {
    cout << "Nama Pelajaran : " << p.namaPel << endl;
    cout << "Kode Pelajaran : " << p.kodePel << endl;
}

int main() {
    const int MAX = 5;
    Pelajaran daftarPelajaran[MAX];
    Pelajaran *ptr;
    int n;

    cout << "Masukkan jumlah pelajaran (maks 5): ";
    cin >> n;
    cin.ignore();

    if (n > MAX) {
        cout << "Jumlah pelajaran melebihi batas!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string nama, kode;
        cout << "\nPelajaran ke-" << i + 1 << endl;
        cout << "Masukkan nama pelajaran : ";
        getline(cin, nama);
        cout << "Masukkan kode pelajaran : ";
        getline(cin, kode);

        daftarPelajaran[i] = createPelajaran(nama, kode);
    }

    cout << "\n=== DATA SEMUA PELAJARAN ===\n";
    ptr = daftarPelajaran;
    for (int i = 0; i < n; i++) {
        cout << "Data Pelajaran ke-" << i + 1 << endl;
        tampilPelajaran(*(ptr + i));
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu3_modul3/output-unguided3-modul3.png)

Program ini digunakan untuk menyimpan dan menampilkan beberapa data pelajaran (maksimal 5 data), menggunakan array struct, pointer, dan fungsi.

## Kesimpulan


## Referensi
[1] <br>