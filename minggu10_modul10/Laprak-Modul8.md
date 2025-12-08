# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori
Struktur data merupakan cara untuk menyimpan dan mengelola data agar dapat digunakan secara efisien dalam pemrograman. Salah satu struktur data yang penting adalah Tree (pohon), yang digunakan untuk merepresentasikan hubungan hierarkis antara data. Tree sering digunakan dalam berbagai aplikasi seperti sistem file komputer, kompresi data, pengurutan, pencarian, serta representasi ekspresi matematika. Melalui pemahaman konsep tree, mahasiswa dapat memahami bagaimana data saling terhubung dalam struktur bertingkat dan bagaimana operasi seperti penelusuran, pencarian, serta penghapusan dapat dilakukan secara efisien.

### A. Tree <br/>
Tree atau pohon adalah struktur data non-linear yang terdiri dari sekumpulan node yang saling terhubung melalui hubungan hierarki. Setiap tree memiliki satu node utama yang disebut root, yang menjadi titik awal seluruh cabang. Node lain dapat memiliki satu atau lebih node anak (child). Node yang tidak memiliki anak disebut leaf node, sedangkan node yang memiliki anak disebut internal node. Tree digunakan untuk menyimpan data yang memiliki hubungan bertingkat, seperti struktur organisasi, direktori komputer, atau relasi antar data.

### B. Binary Tree <br/>
Binary Tree merupakan jenis tree di mana setiap node hanya dapat memiliki maksimal dua anak, yaitu anak kiri (left child) dan anak kanan (right child). Struktur ini memungkinkan pengelolaan data yang lebih efisien dalam proses pencarian dan pengurutan. Penelusuran atau traversal pada binary tree dapat dilakukan dalam tiga urutan utama, yaitu Preorder (Root–Left–Right), Inorder (Left–Root–Right), dan Postorder (Left–Right–Root). Ketiga metode ini memberikan cara yang berbeda dalam membaca atau menampilkan isi tree tergantung pada kebutuhan algoritma.

## Guided 
### 1. Guided 1

```C++
#include<iostream>
using namespace std;

int pangkat_2(int x) {//adalah pengkatnya
    if(x == 0) {//basis
        return 1;
    } else if (x > 0) {//rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: "; 
    cin >> x;
    cout << endl;
    cout << " pangkat 2 dari " << x << " adalah : " << pangkat_2(x) ;

    return 0;
}
```

Program ini digunakan untuk menghitung nilai 2 pangkat x (2^x) dengan menggunakan fungsi rekursif.

### 2. Guided 2

file: BST1.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

#endif
```

file: BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

file: main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

Program ini merupakan implementasi Binary Search Tree (BST) menggunakan C++. Struktur data ini menyimpan nilai secara terurut, di mana nilai lebih kecil berada di subtree kiri dan nilai lebih besar di subtree kanan. Fungsi createTree digunakan untuk membuat tree kosong, sedangkan insertNode menambahkan data baru secara rekursif sesuai aturan BST. Program juga menyediakan tiga jenis traversal, yaitu preorder, inorder, dan postorder, untuk menampilkan isi tree dengan urutan berbeda. Selain itu, fungsi countNodes menghitung jumlah node, dan treeDepth menentukan kedalaman tree. Secara keseluruhan, program ini menunjukkan penerapan konsep rekursi dan pointer dalam pengelolaan struktur data pohon yang efisien dan terstruktur.

### 3. Guided 3

file: BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

//FUNCTION & PEOSEDUR BARU
//search
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

//mostleft & mostright
address mostLeft(address root); //function untuk menampilkan mostleft atau node paling kiri
                                // (node dengan nilai terkecil) didalam BST
address mostRight(address root); //function untuk menampilkan mostright atau node paling kanan
                                 // (node dengan nilai terbesar) didalam BST

//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu didalam BST
                                            //(menghapus berdasarkan parameter infotype)
void deleteTree(address &root); //procedur untuk menghapus BST (menghapus seluruh node BST)
#endif
```

file: BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

file: main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```

Program ini mengimplementasikan Binary Search Tree (BST) dengan fitur menambah, mencari, menelusuri, dan menghapus data. Nilai disusun secara terurut, di mana data lebih kecil berada di kiri dan lebih besar di kanan. Program juga dapat menampilkan parent, sibling, serta nilai terkecil dan terbesar. Melalui penggunaan rekursi dan pointer, program ini memperlihatkan cara mengelola data secara efisien dalam struktur pohon biner.


## Unguided 

### 1. Soal Unguided 1

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef int infotype;
//typedef Node* address;
struct Node{
    infotype info;
    Node* left;
    Node* right;
};
typedef Node* address;
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root,infotype x);
void printInOrder(address  root);

#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;
address alokasi(infotype x){
    address P = new Node;
    P -> info = x;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}
void insertNode(address &root, infotype x){
    if(root == NULL){
        root = alokasi(x);
    }else if(x < root -> info){
        insertNode(root -> left, x);
    }else{
        insertNode(root -> right, x);
    }
}
address findNode(address root, infotype x){
    if(root == NULL){
        return NULL;
    }
    if(root -> info == x){
        return root;
    }
    if(x < root -> info){
        return findNode(root -> left, x);
    }else{
        return findNode(root -> right, x);
    }
}
void printInOrder(address root){
    if (root == nullptr) return;

    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
cout << "Hello World" << endl;
address root = NULL;
insertNode(root,1);
insertNode(root,2);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
printInOrder(root);
return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu10_modul10/output-unguided1-modul10.png)

Program ini mengimplementasikan Binary Search Tree (BST) sederhana menggunakan C++. Data disimpan secara terurut, dengan nilai lebih kecil di kiri dan lebih besar di kanan. Fungsi insertNode menambahkan data secara rekursif, findNode mencari nilai tertentu, dan printInOrder menampilkan data secara berurutan. Program ini menunjukkan penerapan dasar rekursi dan struktur pohon biner dalam pengelolaan data.

### 2. Soal Unguided 2

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef int infotype;
//typedef Node* address;
struct Node{
    infotype info;
    Node* left;
    Node* right;
};
typedef Node* address;
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root,infotype x);
void printInOrder(address  root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);


#endif
```

bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;
address alokasi(infotype x){
    address P = new Node;
    P -> info = x;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}
void insertNode(address &root, infotype x){
    if(root == NULL){
        root = alokasi(x);
    }else if(x < root -> info){
        insertNode(root -> left, x);
    }else{
        insertNode(root -> right, x);
    }
}
address findNode(address root, infotype x){
    if(root == NULL){
        return NULL;
    }
    if(root -> info == x){
        return root;
    }
    if(x < root -> info){
        return findNode(root -> left, x);
    }else{
        return findNode(root -> right, x);
    }
}
void printInOrder(address root){
    if (root == nullptr) return;

    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}

int hitungJumlahNode(address root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + hitungJumlahNode(root -> left) + hitungJumlahNode(root -> right);
    }
}
int hitungTotalInfo(address root){
    if(root == NULL){
        return 0;
    }else{
        return root -> info + hitungTotalInfo(root -> left) + hitungTotalInfo(root -> right);
    }
}
int hitungKedalaman(address root, int start){
    if(root == NULL){
        return start;
    }else{
        int leftDepth = hitungKedalaman(root -> left, start );
        int rightDepth = hitungKedalaman(root -> right, start );
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

main.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;


int main() {
    cout << "Hello World" << endl;
    address root = NULL;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInOrder(root);
    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalInfo(root)<<endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu10_modul10/output-unguided2-modul10.png)

Program ini mengimplementasikan Binary Search Tree (BST) dengan fitur penyimpanan, penelusuran, dan perhitungan data. Struktur tree dibangun secara rekursif dengan nilai lebih kecil di kiri dan lebih besar di kanan. Fungsi printInOrder menampilkan data secara terurut, sementara hitungJumlahNode, hitungTotalInfo, dan hitungKedalaman digunakan untuk menghitung jumlah node, total nilai, serta kedalaman tree. Program ini menunjukkan penggunaan rekursi dalam pengelolaan dan analisis struktur data pohon secara efisien.

### 3. Soal Unguided 3

```C++
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* address;

// Membuat node
address alokasi(int x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

// Pre-order: Root, Left, Right
void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order: Left, Right, Root
void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

int main() {
    address root = NULL;
    root = alokasi(6);                 // root

    root->left = alokasi(4);           // 6 -> left  = 4
    root->right = alokasi(7);          // 6 -> right = 7

    root->left->left = alokasi(2);     // 4 -> left  = 2
    root->left->right = alokasi(5);    // 4 -> right = 5

    root->left->left->left = alokasi(1); // 2 -> left  = 1
    root->left->left->right = alokasi(3); // 2 -> right = 3

    cout << "Pre-Order traversal  : ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu10_modul10/output-unguided3-modul10.png)

Program ini merupakan implementasi dasar Binary Tree menggunakan C++. Setiap node memiliki data serta pointer ke anak kiri dan kanan, dan node dibuat melalui fungsi alokasi. Struktur tree dibentuk secara manual, lalu ditelusuri menggunakan dua metode rekursif: pre-order (Root–Left–Right) dan post-order (Left–Right–Root). Program ini menunjukkan cara membangun dan menelusuri tree secara hierarkis menggunakan konsep rekursi.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Binary Tree dan Binary Search Tree (BST) merupakan struktur data hierarkis yang sangat berguna untuk mengelola data secara efisien. BST memudahkan proses pencarian, penambahan, dan penghapusan data karena setiap nilai ditempatkan berdasarkan urutan tertentu. Dengan penerapan rekursi dan pointer, berbagai operasi seperti traversal, pencarian, dan perhitungan dapat dilakukan dengan sederhana namun tetap efisien. Melalui implementasi ini, mahasiswa dapat memahami bagaimana tree bekerja dalam menyusun dan mengelola data yang saling berhubungan secara hierarkis.

## Referensi
[1] Anhar, Belajar Struktur Data dengan C++, Informatika, Bandung, 2019. <br>
[2] Rinaldi Munir, Struktur Data dan Algoritma, Informatika, Bandung, 2018. <br>
[3] Dony Ariyus, Algoritma dan Struktur Data Menggunakan C++, Andi Offset, Yogyakarta, 2020. <br>