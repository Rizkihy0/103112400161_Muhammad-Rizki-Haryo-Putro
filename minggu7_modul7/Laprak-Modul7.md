# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori
Stack merupakan struktur data linear yang bekerja dengan prinsip LIFO (Last In, First Out), yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Konsep ini sangat penting dalam pemrograman karena digunakan dalam berbagai proses seperti pengelolaan call stack saat fungsi dipanggil, proses undo/redo, serta pengolahan ekspresi matematika. Implementasi stack dapat dilakukan menggunakan array maupun linked list, di mana array bersifat statis dan lebih sederhana, sedangkan linked list bersifat dinamis dan lebih fleksibel dalam penggunaan memori. Pada praktiknya, stack memiliki operasi dasar seperti push, pop, dan pengecekan kondisi kosong, yang keseluruhannya mendukung perilaku bertumpuk sesuai prinsip LIFO.

### A. Stack <br/>
Stack adalah struktur data bertumpuk yang hanya memperbolehkan penambahan dan penghapusan elemen melalui satu sisi, yaitu bagian atas stack (top). Karena hanya satu ujung yang digunakan, proses penyimpanan dan pengambilan data menjadi lebih teratur dan mengikuti aturan LIFO. Struktur ini banyak digunakan dalam algoritma rekursif, penelusuran graf, kompilasi program, dan mekanisme navigasi aplikasi.


## Guided 
### 1. Guided 1

file: stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

file: stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

file: main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini membuat stack menggunakan linked list dengan operasi push, pop, update, tampilkan isi, dan cari data. Elemen baru selalu masuk di bagian atas, dan penghapusan juga dari atas sesuai prinsip LIFO. Di main, lima data dimasukkan, dua dihapus, beberapa posisi di-update, lalu stack ditampilkan dan dilakukan pencarian data.

### 2. Guided 2

file: stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan eleman stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif
```

file: stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

file: main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

Program ini membuat stack menggunakan array dengan operasi dasar seperti push, pop, cek kosong/penuh, dan menampilkan isi stack. Nilai dimasukkan dan dihapus dari bagian atas sesuai konsep LIFO. Fungsi balikStack() membalik urutan elemen stack dengan bantuan dua stack sementara. Pada main, beberapa operasi dilakukan untuk membentuk stack, menampilkannya, membalik urutannya, dan menampilkan hasil akhirnya.


## Unguided 

### 1. Soal Unguided 1

stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#define MaxEl 20
#define Nil -1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
```

stack.cpp
```C++
#include "stack.h"
using namespace std;

void CreateStack(Stack &S){
    S.top = Nil;
}
void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.info[S.top] = x;
    }else{
        cout << "Stack penuh" << endl;
    }

}
infotype pop(Stack &S) {
    infotype x = -999;  
    if (!isEmpty(S)) {  
        x = S.info[S.top];  
        S.top--;  
    } else {
        cout << "Stack Kosong!" << endl;  
    }
    return x; 
}
void printInfo(Stack S) {
    if (isEmpty(S)) {  
        cout << "Stack Kosong" << endl;  
    } else {
        cout << "[TOP] ";  
        for (int i = S.top; i >= 0; i--) {  
            cout << S.info[i] << " ";  
        }
        cout << endl; 
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
bool isEmpty(Stack S){
    return S.top == Nil;
}
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  
}
void pushAscending(Stack &S, int x){
    Stack Temp1, Temp2;
    CreateStack(Temp1);
    CreateStack(Temp2);
    int t;
    while(!isEmpty(S)){
        t = pop(S);
        if (t < x){
            push(Temp1, t);
            //break;
        }else{
            push(Temp2, t);
        }
    }
    while(!isEmpty(Temp1)){
        push(S, pop(Temp1));
    }
    push(S, x);
    while(!isEmpty(Temp2)){
       
        push(S, pop(Temp2));
    }
}
void getInputStream(Stack &S) {
    char c;

    cout << "Masukkan input: ";

    cin.get(c);           // baca karakter pertama

    while (c != '\n') {   // berhenti jika user tekan ENTER
        push(S, c - '0'); 
        cin.get(c);       // baca karakter berikutnya
    }
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;
int main(){
    cout << "Hello World!" << endl;
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S,2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    //push ascending
    cout << "Hello World!" << endl;
    CreateStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    //input stream
    cout << "Hello World!" << endl;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu7_modul7/output-unguided1-modul7.png)

Program ini membuat dan mengelola struktur data stack menggunakan array. Ia menyediakan operasi dasar seperti push, pop, pengecekan kosong/penuh, dan menampilkan isi stack. Program juga memiliki fitur tambahan yaitu membalik isi stack (balikStack), memasukkan data secara terurut menaik (pushAscending), serta membaca input angka per karakter (getInputStream). Di fungsi main, semua fitur tersebut diuji dengan beberapa operasi untuk menunjukkan cara kerja stack dan fungsi tambahannya.


## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa stack adalah struktur data fundamental yang menerapkan prinsip LIFO sehingga memungkinkan pengelolaan data secara terurut dari atas ke bawah. Implementasinya dapat menggunakan array maupun linked list, masing-masing dengan kelebihan yang berbeda. Berbagai operasi seperti push, pop, pencarian data, membalik urutan, dan memasukkan data terurut menunjukkan bahwa stack dapat dikembangkan untuk berbagai kebutuhan pemrograman. Praktikum ini membantu memahami konsep stack secara teori sekaligus implementasinya dalam kode C++.

## Referensi
[1] Rinaldi Munir. Algoritma dan Struktur Data. Informatika Bandung, 2016. <br>
[2] Rosa A.S., & Shalahuddin, M. Rekayasa Perangkat Lunak: Terstruktur dan Berorientasi Objek. Informatika Bandung, 2018. <br>
[3] Wahana Komputer. Struktur Data Menggunakan C++. Andi Publisher, 2010. <br>