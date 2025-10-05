# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori
Struktur data menjelaskan koleksi atau kelompok data yang dapat dibedakan oleh organisasi dan operasi yang dilakukan terhadapnya. Penggunaan struktur data yang tepat selama proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, sehingga menjadikan program secara keseluruhan lebih sederhana

### A. Array<br/>
Array merupakan struktur data yang menyimpan elemen dalam satu blok memori dengan akses cepat menggunakan indeks

### B. Pointer<br/>
Pointer adalah variabel yang menyimpan alamat memori dari variabel lain

### c. Prosedur<br/>
Prosedur dapat mengembalikan atau tidak mengembalikan nilai hasil; untuk melakukannya, diperlukan suatu variabel tertentu. Proses pencetakan hasil atau nilai disimpan dalam blok subrutin tersendiri di program utama, yang kemudian diberi nama prosesnya


## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j=0;
    while (j < 5) {
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program meminta input dan menampilkan isi array menggunakan perulangan

### 2. Array Pointer

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i<5; ++i){
        cout << " Elemen array ke-" << i+1 << " menggunakan pointer : " << *(ptr + i) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "elemen array ke-" << i + 1 << " menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}
 ```
Program menampilkan elemen array dengan pointer dan indeks

### 3. Fungsi Prosedur

```C++
#include <iostream>
using namespace std;

int cariMAX (int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totaljumlah = 0;
    for(int i = 0; i < ukuran; i ++){
        totaljumlah += arr[i];
    }
    cout << " total penjumlahan : " << totaljumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }

    cout << " total perkalian : " << totalKali << endl;
}
    int main (){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "masukan nilai arrray ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran)<< endl;

    operasiAritmatika(arr, ukuran);
    return 0;

}

```
Program mencari nilai maksimum dan menghitung hasil aritmatika array dengan prosedur

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :

```C++
#include <iostream>
using namespace std;

const int N = 3;

void jumlahMatriks(int A[N][N], int B[N][N]) {
    int C[N][N];
    cout << "\nHasil Penjumlahan Matriks:\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}

void kurangMatriks(int A[N][N], int B[N][N]) {
    int C[N][N];
    cout << "\nHasil Pengurangan Matriks:\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}

void kaliMatriks(int A[N][N], int B[N][N]) {
    int C[N][N];
    cout << "\nHasil Perkalian Matriks:\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] = 0;
            for(int k=0; k<N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matriksA[N][N] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int matriksB[N][N] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int pilihan;
    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: jumlahMatriks(matriksA, matriksB); break;
            case 2: kurangMatriks(matriksA, matriksB); break;
            case 3: kaliMatriks(matriksA, matriksB); break;
            case 4: cout << "Keluar program.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while(pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu2_modul2/output-unguided1-modul2.png)

Program menghitung operasi matriks 3x3 menggunakan prosedur dan menu switch-case

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0;
    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    luas = (*ptrPanjang) * (*ptrLebar);
    cout << "Luas awal persegi panjang = " << luas << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << "Panjang baru = " << panjang << endl;
    cout << "Lebar baru   = " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    cout << "Luas baru persegi panjang = " << luas << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu2_modul2/output-unguided2-modul2.png)

Program menghitung luas persegi panjang menggunakan pointer dan menampilkan hasil setelah nilai diubah.

## Kesimpulan
Array digunakan untuk menyimpan dan mengelola sekumpulan data dengan tipe yang sama secara berurutan di memori, sehingga memudahkan proses akses dan pengolahan data. Pointer berfungsi untuk menyimpan alamat memori dari suatu variabel, yang memungkinkan pengaksesan dan perubahan nilai secara langsung, menjadikan program lebih efisien dalam penggunaan memori. Sementara itu, prosedur digunakan untuk memecah program menjadi bagian-bagian kecil yang terstruktur dan mudah dipahami.

## Referensi
[1] Wibowo, A. (2021). Pemrograman Dasar C++ untuk Pemula. Andi Publisher.<br>