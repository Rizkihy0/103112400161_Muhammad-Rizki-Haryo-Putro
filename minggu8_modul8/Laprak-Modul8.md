# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori
Struktur data adalah metode untuk menyimpan dan mengelola data agar dapat diakses dan diproses dengan efisien. Dalam pemrograman, struktur data membantu menyusun data supaya lebih teratur dan mempermudah operasi seperti pencarian, penyimpanan, serta penghapusan. Salah satu struktur data yang banyak digunakan adalah Queue, yang sering dijumpai dalam berbagai sistem komputasi maupun situasi dunia nyata seperti antrean layanan.

### A.  <br/>
Queue adalah struktur data linear yang bekerja menggunakan prinsip FIFO (First In First Out), artinya elemen yang pertama dimasukkan akan menjadi elemen pertama yang diambil. Queue memiliki dua operasi utama yaitu enqueue (menambahkan data) dan dequeue (menghapus data). Struktur queue dapat diimplementasikan menggunakan array atau linked list. Pada implementasi array, sering digunakan konsep circular queue agar memori digunakan lebih efisien. Queue banyak diterapkan dalam sistem komputer seperti antrian proses pada CPU, buffer data, dan algoritma pencarian BFS.

## Guided 
### 1. Guided 1

file: queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
} ;

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);

#endif
```

file: queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

file: main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```
Program ini merupakan implementasi struktur data queue berbasis linked list dalam C++. Program menyediakan fitur seperti enqueue, dequeue, update data, mencari data, dan menampilkan isi queue. Operasi dilakukan mengikuti prinsip FIFO (First In First Out), serta memanfaatkan alokasi memori dinamis untuk menambah dan menghapus elemen sesuai kebutuhan.

### 2. Guided 2

file: queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

file: queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

file: main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);

    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

Program ini mengimplementasikan queue statis menggunakan array dengan sistem circular queue. Fitur yang disediakan meliputi enqueue, dequeue, pengecekan kondisi penuh atau kosong, serta menampilkan isi queue. Struktur ini bekerja berdasarkan prinsip FIFO (First In First Out).


## Unguided 

### 1. Soal Unguided 1

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

typedef int ElementType;

struct Queue {
    ElementType data[MAX_QUEUE];
    int front;
    int rear;
};

void createQueue(Queue &Q);
bool isEmpty(const Queue &Q);
bool isFull(const Queue &Q);
void enqueue(Queue &Q, ElementType x);
ElementType dequeue(Queue &Q);
void printQueue(const Queue &Q);

#endif
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
    Q.front = 0;
    Q.rear = 0;
}

bool isEmpty(const Queue &Q){
    return (Q.front == 0);
}

bool isFull(const Queue &Q){
    return (Q.rear == MAX_QUEUE);
}

void enqueue(Queue &Q, ElementType x){
    if(isFull(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }

    if(isEmpty(Q)){
        Q.front = Q.rear = 1;
        Q.data[0] = x;
    } else {
        Q.rear++;
        Q.data[Q.rear - 1] = x;
    }
}

ElementType dequeue(Queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }

    ElementType removed = Q.data[0];

    for(int i = 0; i < Q.rear - 1; i++){
        Q.data[i] = Q.data[i + 1];
    }

    Q.rear--;

    if(Q.rear == 0){
        Q.front = 0;
    }

    return removed;
}

void printQueue(const Queue &Q){
    int F, R;

    if(isEmpty(Q)){
        F = R = -1;
    } else {
        F = Q.front - 1;
        R = Q.rear - 1;
    }

    cout << F << " - " << R << " | ";

    if(isEmpty(Q)){
        cout << "empty queue";
    } else {
        for(int i = 0; i < Q.rear; i++){
            cout << Q.data[i] << " ";
        }
    }
    cout << endl;
}
```

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " F - R | Queue Content" << endl;
    cout << "-------------------------" << endl;

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    dequeue(Q);   printQueue(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu8_modul8/output-unguided1-modul8.png)

Program ini menunjukkan implementasi queue berbasis array dengan prinsip FIFO, mendukung operasi enqueue, dequeue, pengecekan penuh/kosong, dan menampilkan isi queue, di mana proses dequeue dilakukan dengan menggeser elemen.

### 2. Soal Unguided 2

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

typedef int ItemType;

struct Queue {
    ItemType data[MAX_QUEUE];
    int front;
    int rear;
};

void initQueue(Queue &Q);
bool isEmpty(const Queue &Q);
bool isFull(const Queue &Q);
void enqueue(Queue &Q, ItemType value);
ItemType dequeue(Queue &Q);
void printQueue(const Queue &Q);

#endif
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void initQueue(Queue &Q) {
    Q.front = 0;
    Q.rear = -1;
}

bool isEmpty(const Queue &Q) {
    return Q.rear < Q.front;
}

bool isFull(const Queue &Q) {
    return Q.rear == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, ItemType value) {
    if (!isFull(Q)) {
        Q.rear++;
        Q.data[Q.rear] = value;
    } else {
        cout << "Queue penuh!\n";
    }
}

ItemType dequeue(Queue &Q) {
    if (!isEmpty(Q)) {
        ItemType value = Q.data[Q.front];
        Q.front++;

        // Reset jika kosong
        if (Q.front > Q.rear) {
            Q.front = 0;
            Q.rear = -1;
        }
        
        return value;
    }
    cout << "Queue kosong!\n";
    return -1;
}

void printQueue(const Queue &Q) {
    cout << Q.front << " - " << Q.rear << " | ";

    if (isEmpty(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << "\n";
}
```

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World\n";
    
    Queue Q;
    initQueue(Q);

    cout << "----------------------\n";
    cout << " F - R | Queue info\n";
    cout << "----------------------\n";

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    dequeue(Q);   printQueue(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu8_modul8/output-unguided2-modul8.png)

Program ini menunjukkan implementasi struktur data queue berbasis array dengan prinsip FIFO, menyediakan operasi enqueue, dequeue, pengecekan kondisi penuh atau kosong, serta menampilkan isi queue. Queue akan otomatis reset ketika kosong sehingga pengelolaan indeks lebih efisien.

### 3. Soal Unguided 3

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

typedef int ItemType;

struct Queue {
    ItemType data[MAX_QUEUE];
    int front;
    int rear;
};

void initQueue(Queue &Q);
bool isEmpty(const Queue &Q);
bool isFull(const Queue &Q);
void enqueue(Queue &Q, ItemType value);
ItemType dequeue(Queue &Q);
void printQueue(const Queue &Q);

#endif
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void initQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmpty(const Queue &Q) {
    return (Q.front == -1 && Q.rear == -1);
}

bool isFull(const Queue &Q) {
    return ((Q.rear + 1) % MAX_QUEUE == Q.front);
}

void enqueue(Queue &Q, ItemType value) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.front = 0;
        Q.rear = 0;
    } else {
        Q.rear = (Q.rear + 1) % MAX_QUEUE;
    }

    Q.data[Q.rear] = value;
}

ItemType dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    ItemType removed = Q.data[Q.front];

    if (Q.front == Q.rear) {
        Q.front = Q.rear = -1; // queue kembali kosong
    } else {
        Q.front = (Q.front + 1) % MAX_QUEUE;
    }

    return removed;
}

void printQueue(const Queue &Q) {
    cout << " " << Q.front << " - " << Q.rear << "\t | ";

    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.front;
    while (true) {
        cout << Q.data[i] << " ";
        if (i == Q.rear) break;
        i = (i + 1) % MAX_QUEUE;
    }

    cout << endl;
}
```

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    initQueue(Q);

    cout << "----------------------" << endl;
    cout << " F - R \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    dequeue(Q);    printQueue(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu8_modul8/output-unguided3-modul8.png)

Program ini menggunakan konsep circular queue dengan array untuk mengelola data secara FIFO. Indeks bergerak melingkar menggunakan modulo sehingga ruang lebih efisien, serta mendukung operasi enqueue, dequeue, pengecekan penuh/kosong, dan tampilan isi queue.

## Kesimpulan
Queue merupakan struktur data yang bekerja berdasarkan konsep FIFO. Melalui praktikum ini, mahasiswa dapat memahami cara kerja enqueue, dequeue, pengecekan kondisi queue, dan implementasi queue menggunakan array maupun linked list. Pemahaman ini penting karena queue banyak digunakan dalam berbagai proses komputasi dan sistem pemrograman.

## Referensi
[1] Arifin, Z. (2020). Struktur Data dan Algoritma. Jakarta: Informatika. <br>
[2] Hakim, R. (2021). Pemrograman Dasar C++ dan Struktur Data. Bandung: Garuda Media. <br>
[3] Junaidi. (2019). Struktur Data: Konsep dan Implementasi Menggunakan C++. Yogyakarta: Andi Publisher. <br>