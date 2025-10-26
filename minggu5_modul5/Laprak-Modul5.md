# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori
Linked list adalah salah satu struktur data dinamis yang terdiri dari kumpulan node, di mana setiap node berisi data dan pointer yang menunjuk ke node berikutnya. Berbeda dengan array yang memiliki ukuran tetap dan penyimpanan berurutan di memori, linked list lebih fleksibel karena dapat menambah atau menghapus data tanpa perlu menggeser elemen lain. Struktur ini sering digunakan dalam pemrograman untuk mengelola data secara efisien, terutama ketika ukuran data tidak diketahui secara pasti di awal.

Dalam linked list, terdapat beberapa operasi penting seperti penambahan (insert), penghapusan (delete), pembaruan (update), dan pencarian (search). Dua metode pencarian yang umum digunakan adalah binary search dan linear search, yang masing-masing memiliki cara kerja dan efisiensi yang berbeda.

### A.Pengertian Binary Search pada Linked List <br/>
Binary search merupakan algoritma pencarian yang menggunakan metode divide and conquer dengan cara membagi ruang pencarian menjadi dua bagian setiap kali dilakukan perbandingan. Algoritma ini sangat efektif digunakan pada data yang sudah terurut karena dapat mempercepat proses pencarian. Namun, pada linked list, binary search menjadi kurang efisien karena untuk menemukan elemen tengah, program harus menelusuri node satu per satu dari awal. Hal ini menyebabkan kompleksitas waktu meningkat menjadi O(n log n), berbeda dengan array yang hanya memerlukan O(log n). Oleh karena itu, binary search jarang digunakan pada linked list dalam praktik nyata.

### B. Pengertian Linear Search pada Linked List<br/>
Linear search atau sequential search adalah metode pencarian sederhana dengan cara menelusuri setiap node secara berurutan dari awal hingga akhir list. Pada setiap langkah, data dalam node dibandingkan dengan nilai yang dicari, dan pencarian berhenti jika ditemukan kecocokan atau mencapai akhir list. Linear search mudah diimplementasikan, tidak memerlukan data terurut, dan sangat cocok untuk digunakan pada linked list. Namun, karena prosesnya memeriksa setiap elemen satu per satu, metode ini memiliki kompleksitas waktu O(n) dan menjadi kurang efisien jika jumlah data sangat banyak.

## Guided 
### 1. Guided 1

file: listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL
#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address; // mendefniskan alias address sbgi pointer ke struct

struct node{ //  node unutk
    dataBuah isiData;
    address next;
};
struct linkedList{ //linked list
   address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst (linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLst(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address Prev);

#endif
```

file: listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.jumlah = jumlah; 
    nodeBaru->isiData.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isiData.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isiData.nama << ", Jumlah : " << nodeBantu->isiData.jumlah << ", Harga : " << nodeBantu->isiData.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isiData.nama;
        cout << "Jumlah : ";
        cin >> List.first->isiData.jumlah;
        cout << "Harga : ";
        cin >> List.first->isiData.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isiData.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isiData.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isiData.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isiData.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isiData.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isiData.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isiData.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

file: main.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("jeruk" , 100, 3000);
    nodeB = alokasi("apel", 75, 4000);
    nodeC = alokasi("pir" , 87, 5000 );
    nodeD = alokasi("semangka", 43, 11500);
    nodeE = alokasi("durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);
    cout << "isi lost detelah dilakukan insert" << endl;
    printList(List);
    cout << " Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "isi list setelah dlakukan update " << endl;
    printList(List);
    cout << "jumlah node : " << endl;
    cout << endl;
    

    return 0;
}
```
Program ini bertujuan untuk mengelola data buah menggunakan struktur data Singly Linked List

### 2. Guided 2

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```

Program ini merupakan implementasi dasar dari struktur data Singly Linked List dalam C++, yang dilengkapi dengan penambahan node di akhir list, Pencarian elemen secara linear

### 2. Guided 3

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Program ini merupakan implementasi pencarian biner (binary search) pada struktur data Singly Linked List

## Unguided 

### 1. Soal Unguided 1

```C++
#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node* next; // pointer ke node berikutnya
};

// Fungsi untuk menampilkan linked list
void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Implementasi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    // Hitung ukuran linked list
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        // Pindah ke node tengah
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        // Cek apakah data ditemukan
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        // Jika data midNode lebih kecil dari key, cari di bagian kanan
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            
            // Jika size baru adalah 1, periksa langsung elemen terakhir
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) {
                    return lastNode;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            start = midNode->next;
            size = newSize;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        // Jika data midNode lebih besar dari key, cari di bagian kiri
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            // Jika size baru adalah 1, periksa langsung elemen pertama
            if (mid == 1) {
                if (start->data == key) {
                    return start;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            size = mid;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}

// Prosedur untuk menambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk membersihkan memori
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    // Data linked list sudah ditentukan dari awal
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Tampilkan isi linked list
    displayList(head);
    
    // Pencarian pertama - nilai 40
    cout << "Mencari nilai: 40";
    
    Node* result = binarySearch(head, 40);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 40 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // Pencarian kedua - nilai 25
    cout << "Mencari nilai: 25";
    
    result = binarySearch(head, 25);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // Bersihkan memori
    deleteList(head);
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu5_modul5/output-unguided1-modul5.png)

Struktur Node menyimpan data dan pointer ke node berikutnya. Fungsi append() menambah data, displayList() menampilkan isi list, dan binarySearch() mencari nilai dengan membandingkan data tengah hingga ditemukan atau tidak. Pada main(), program membuat list berisi 10–60, lalu mencari nilai 40 (ditemukan) dan 25 (tidak ditemukan). Program ini menunjukkan konsep binary search, namun kurang efisien karena linked list tidak mendukung akses langsung ke elemen tengah.

### 2. Soal Unguided 2

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;     
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; 
    if (!head) head = newNode; 
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; 
        temp->next = newNode;
    }
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int index = 1;

    cout << "\nProses Pencarian:\n";
    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;

        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return current; 
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr; 
}

int main() {
    Node* head = nullptr;

    cout << "● LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n";

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << endl;

    Node* hasil1 = linearSearch(head, cari1);

    if (hasil1) {
        cout << "\nHasil: Nilai " << cari1 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil1 << endl;
        cout << "Data node: " << hasil1->data << endl;
        if (hasil1->next)
            cout << "Node berikutnya: " << hasil1->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "\nHasil: Nilai " << cari1 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    int cari2 = 25;
    cout << "\nMencari nilai: " << cari2 << endl;

    Node* hasil2 = linearSearch(head, cari2);

    if (hasil2) {
        cout << "\nHasil: Nilai " << cari2 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil2 << endl;
        cout << "Data node: " << hasil2->data << endl;
        if (hasil2->next)
            cout << "Node berikutnya: " << hasil2->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "\nHasil: Nilai " << cari2 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}
```

### Output Unguided 2 :
##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu5_modul5/output-unguided2-modul5.png)

Struktur Node menyimpan data dan pointer ke node berikutnya. Fungsi append() menambah node di akhir list, sedangkan linearSearch() mencari nilai dengan memeriksa setiap node secara berurutan hingga ditemukan atau tidak. Dalam main(), program membuat list berisi 10–50 dan mencari nilai 30 (ditemukan) serta 25 (tidak ditemukan). Program ini menunjukkan cara kerja pencarian data secara berurutan pada linked list.

## Kesimpulan
linked list merupakan struktur data dinamis yang terdiri dari kumpulan node, di mana setiap node memiliki data dan pointer yang menunjuk ke node berikutnya. Struktur ini memungkinkan pengelolaan data dilakukan secara fleksibel tanpa perlu menggeser elemen seperti pada array. Dalam praktikum ini, diterapkan dua metode pencarian yaitu linear search dan binary search. Linear search bekerja dengan menelusuri setiap node secara berurutan dari awal hingga akhir list. Metode ini mudah diimplementasikan, tidak memerlukan data yang terurut, namun kurang efisien pada jumlah data yang besar karena memiliki kompleksitas waktu O(n). Sementara itu, binary search menggunakan prinsip divide and conquer untuk mempercepat proses pencarian, tetapi pada linked list metode ini menjadi kurang optimal karena tidak mendukung akses langsung terhadap elemen tengah, sehingga kompleksitasnya meningkat menjadi O(n log n). Secara keseluruhan, dapat disimpulkan bahwa linear search lebih sesuai digunakan pada struktur data linked list, sedangkan binary search lebih efisien diterapkan pada struktur data seperti array yang mendukung akses indeks langsung.

## Referensi
[1] Anhar, Panduan Praktis Belajar Pemrograman C++, Mediakom, Yogyakarta, 2010. <br>
[2] Wahana Komputer, Struktur Data Menggunakan C dan C++, Andi Offset, Yogyakarta, 2015. <br>
[3] Rosa A.S. dan M. Shalahuddin, Rekayasa Perangkat Lunak Terstruktur dan Berorientasi Objek, Informatika, Bandung, 2018. <br>