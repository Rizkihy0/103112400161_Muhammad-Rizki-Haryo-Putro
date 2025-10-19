# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori
Linked List merupakan struktur data dinamis yang terdiri atas kumpulan elemen (node) yang saling terhubung melalui pointer. Setiap node berisi data dan pointer yang menunjuk ke node berikutnya. Pada Singly Linked List, hubungan antar-node hanya searah, dan node terakhir menunjuk ke NULL sebagai penanda akhir. Struktur data ini memungkinkan penambahan dan penghapusan data secara efisien tanpa perlu memindahkan elemen lain seperti pada array, meskipun akses data harus dilakukan secara berurutan dari node pertama.

## Guided 
### 1. Guided 1

file: list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

file: list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

file: main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}   
```
Program ini bertujuan untuk mempelajari dan mengimplementasikan operasi dasar pada struktur data Singly Linked List dalam bahasa C++. Data yang disimpan berupa data mahasiswa, yaitu Nama, NIM, Umur

### 2. Guided 2

file: list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

file: list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {

    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { 
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

file: main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini bertujuan untuk mengimplementasikan struktur data Singly Linked List dalam bahasa C++ untuk menyimpan dan mengelola data mahasiswa yang terdiri dari Nama, NIM, Umur


## Unguided 

### 1. Soal Unguided 1

file: Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype data;
    Node* next;
};

struct List {
    Node* head;
};

void createList(List &L);
Node* allocate(infotype value);
void deallocate(Node* &node);
void printList(List L);
void insertFirst(List &L, Node* node);

#endif
```

file: Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.head = NULL;
}

Node* allocate(infotype value) {
    Node* node = new Node;
    if (node != NULL) {
        node->data = value;
        node->next = NULL;
    }
    return node;
}

void deallocate(Node* &node) {
    delete node;
    node = NULL;
}

void printList(List L) {
    Node* current = L.head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertFirst(List &L, Node* node) {
    node->next = L.head;
    L.head = node;
}
```

file: main.cpp
```C++
#include "Singlylist.h"

int main() {
    List linkedList;
    Node *node1, *node2, *node3, *node4, *node5;

    createList(linkedList);

    node1 = allocate(2);
    insertFirst(linkedList, node1);

    node2 = allocate(0);
    insertFirst(linkedList, node2);

    node3 = allocate(8);
    insertFirst(linkedList, node3);

    node4 = allocate(12);
    insertFirst(linkedList, node4);

    node5 = allocate(9);
    insertFirst(linkedList, node5);

    printList(linkedList);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu4_modul4/output-unguided1-modul4.png)

Program ini merupakan implementasi dasar dari Singly Linked List (daftar berantai tunggal) menggunakan bahasa C++, yang digunakan untuk menyimpan dan menampilkan sekumpulan data secara dinamis melalui penggunaan pointer

### 2. Soal Unguided 2

file: singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int InfoType;

struct Node {
    InfoType data;
    Node* next;
};

typedef Node* Address;

struct List {
    Address head;
};

void createList(List &list);
Address allocate(InfoType value);
void deallocate(Address &node);
void printList(List list);

void insertFirst(List &list, Address node);
void deleteFirst(List &list, Address &deletedNode);
void deleteLast(List &list, Address &deletedNode);
void deleteAfter(List &list, Address &deletedNode, Address prevNode);

int countNodes(List list);
void clearList(List &list);

#endif
```

file: singlylist.cpp
```C++
#include "singlylist.h"

void createList(List &list) {
    list.head = NULL;
}

Address allocate(InfoType value) {
    Address node = new Node;
    if (node != NULL) {
        node->data = value;
        node->next = NULL;
    }
    return node;
}

void deallocate(Address &node) {
    delete node;
    node = NULL;
}

void printList(List list) {
    Address current = list.head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertFirst(List &list, Address node) {
    node->next = list.head;
    list.head = node;
}

void deleteFirst(List &list, Address &deletedNode) {
    if (list.head != NULL) {
        deletedNode = list.head;
        list.head = list.head->next;
        deletedNode->next = NULL;
    } else {
        deletedNode = NULL;
    }
}

void deleteLast(List &list, Address &deletedNode) {
    if (list.head != NULL) {
        Address current = list.head;
        if (current->next == NULL) {
            deletedNode = current;
            list.head = NULL;
        } else {
            while (current->next->next != NULL) {
                current = current->next;
            }
            deletedNode = current->next;
            current->next = NULL;
        }
    } else {
        deletedNode = NULL;
    }
}

void deleteAfter(List &list, Address &deletedNode, Address prevNode) {
    if (prevNode != NULL && prevNode->next != NULL) {
        deletedNode = prevNode->next;
        prevNode->next = deletedNode->next;
        deletedNode->next = NULL;
    } else {
        deletedNode = NULL;
    }
}

int countNodes(List list) {
    int count = 0;
    Address current = list.head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void clearList(List &list) {
    Address deletedNode;
    while (list.head != NULL) {
        deleteFirst(list, deletedNode);

    }
}
```

file: main.cpp
```C++
#include "singlylist.h"

int main() {
    List myList;
    Address nodeA, nodeB, nodeC, nodeD, nodeE = NULL;

    createList(myList);

    nodeA = allocate(2);
    insertFirst(myList, nodeA);

    nodeB = allocate(0);
    insertFirst(myList, nodeB);

    nodeC = allocate(8);
    insertFirst(myList, nodeC);

    nodeD = allocate(12);
    insertFirst(myList, nodeD);

    nodeE = allocate(9);
    insertFirst(myList, nodeE);

    deleteFirst(myList, nodeA);
    deleteLast(myList, nodeE);

    Address deletedNode;
    deleteAfter(myList, deletedNode, nodeD);
    deallocate(deletedNode);

    printList(myList);

    cout << "Jumlah node: " << countNodes(myList) << endl;

    clearList(myList);
    cout << "List berhasil terhapus." << endl;
    cout << "Jumlah node: " << countNodes(myList) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu4_modul4/output-unguided2-modul4.png)

Program ini merupakan implementasi Singly Linked List (daftar berantai tunggal) dalam bahasa C++, yang berfungsi untuk mengelola sekumpulan data secara dinamis menggunakan pointer.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Singly Linked List adalah struktur data dinamis yang memungkinkan penambahan dan penghapusan elemen secara efisien menggunakan pointer. Melalui implementasinya, diperoleh pemahaman tentang cara kerja node, alokasi memori, dan pengelolaan data secara terhubung satu arah.

## Referensi
[1] Dony Ariyus, Struktur Data Menggunakan C dan C++, Andi Offset, Yogyakarta, 2018. <br>
[2] Rinaldi Munir, Algoritma dan Pemrograman dalam Bahasa Pascal dan C, Informatika Bandung, 2019. <br>