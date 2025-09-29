# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Rizki Haryo Putro - 103112400161</p>

## Dasar Teori
C++ adalah bahasa pemrograman yang banyak digunakan untuk mempelajari logika pemrograman karena mendukung pemrograman prosedural dan berorientasi objek [1]. Pada praktikum ini digunakan Code::Blocks sebagai IDE yang mempermudah penulisan, kompilasi, dan eksekusi program berkat tampilannya yang sederhana, dukungan multi-compiler, serta fitur debugging [2]. Materi yang dipelajari mencakup penggunaan cin dan cout untuk input-output, operasi aritmatika (+, -, *, /, %), percabangan dengan if-else atau switch-case, serta perulangan for, while, dan do-while untuk menjalankan perintah secara berulang [3].

### A. Operasi Aritmatika<br/>
Operasi aritmatika di C++ digunakan untuk melakukan perhitungan matematis seperti penjumlahan (+), pengurangan (-), perkalian (*), pembagian (/), dan sisa hasil bagi (%). Operator ini dapat digunakan untuk variabel bertipe numerik seperti int atau float, dan hasilnya akan mengikuti tipe data variabel yang digunakan.

### B. Percabangan dan Switch-Case<br/>
Percabangan (if-else) digunakan untuk mengambil keputusan berdasarkan kondisi yang bernilai benar (true) atau salah (false). switch-case digunakan untuk memilih satu dari beberapa opsi berdasarkan nilai variabel tertentu. switch-case lebih efisien ketika ada banyak pilihan yang harus dicek dibanding menggunakan banyak if-else.

### c. Perulangan<br/>
Perulangan (looping) digunakan untuk menjalankan blok kode secara berulang sampai kondisi tertentu terpenuhi. C++ memiliki beberapa jenis perulangan:

for → digunakan jika jumlah pengulangan sudah diketahui.
while → digunakan jika pengulangan bergantung pada kondisi yang dicek di awal.
do-while → mirip dengan while, tetapi selalu mengeksekusi blok kode minimal satu kali sebelum mengecek kondisi.

## Guided 

### 1. Operasi Aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1,angka2 ;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl ;
    cout << "pengurangan :" << angka1 - angka2 << endl ;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" <<  angka1 / angka2 << endl;
}
```
Program menerima dua angka dari pengguna lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian.

### 2. Percabangan dan Switch-Case

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1,angka2 ;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

if (angka1 < angka2){
    cout << angka1 << "kurang dari " << angka2 << endl;
}else {
    cout << angka1 << "lebih dari" << angka2 << endl;
}

if (angka1 == angka2) {
    cout << angka1 << "sama dengan" << angka2 << endl;
}else if (angka1 != angka2) {
    cout << "angka berbeda" << endl;
}

int pilihan ;
cout << "menu" << endl;
cout << "1. pengjumlahan" << endl;
cout << "2. pengurangan " << endl;
cout << "masukan pilihan: " << endl;
cin >> pilihan ;

switch (pilihan) {
    case 1 :
    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << endl;
    break;
    case 2 :
    cout << "pengurangan : " << angka1 + angka2 << endl;
    cout << endl;
    break;
    default :
    cout << "pilihan salah" << endl;
}
    return 0;
}

 ```
Program membandingkan dua angka dengan if-else, lalu menggunakan switch-case untuk memilih operasi aritmatika sesuai pilihan pengguna.

### 3. Perulangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukan angka 1 :";
    cin >> angka1;

    for (int i = 0; i < angka1; i++) {
        cout << i << "-"; 
    }
    cout << endl;
    int j = 10;
    while (j > angka1){
        cout << j << "-";
        j--;
    }
    cout << endl;
    int k = 10;
    do {
        cout << k << "-";
    } while (k < angka1);

    return 0 ;
}
```
Program menampilkan penggunaan perulangan for, while, dan do-while untuk mencetak angka sesuai kondisi.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main(){
    float angka1, angka2;
    cout << "masukkan angka 1: ";
    cin >> angka1;
    cout << "masukkan angka 2: ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << "Perkalian : " << angka1 * angka2 << endl;
    cout << "Pembagian : " << angka1 / angka2 << endl;
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu1_modul1/output-unguided1-modul1.png)

Program sama seperti guided 1, tetapi menggunakan tipe data float sehingga bisa menghitung bilangan desimal.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};
string puluhan[] = {"","sepuluh","dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 10) {
        cout << satuan[n];
    } else if (n < 20) {
        cout << belasan[n - 10];
    } else if (n < 100) {
        cout << puluhan[n / 10];
        if (n % 10 != 0) cout << " " << satuan[n % 10];
    } else if (n == 100) {
        cout << "seratus";
    } else {
        cout << "Di luar jangkauan!";
    }
    cout << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu1_modul1/output-unguided2-modul1.png)

Program membaca angka 0–100 dan menampilkannya dalam bentuk kata menggunakan array string dan percabangan.

### 3. Buatlah program yang dapat memberikan input dan output sbb ......

```C++
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "input : ";
    cin >> n;

    cout << "Output:\n";
    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n - i; s++) cout << "  ";
        if (i > 0) {
            for (int j = i; j >= 1; j--) cout << j << " ";
            cout << "* ";
            for (int j = 1; j <= i; j++) cout << j << " ";
        } else {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rizkihy0/103112400161_Muhammad-Rizki-Haryo-Putro/blob/main/minggu1_modul1/output-unguided3-modul1.png)

Program mencetak pola angka simetris dengan simbol * di tengah menggunakan nested loop.

## Kesimpulan
Pada praktikum ini, saya mempelajari dasar-dasar bahasa C++ mulai dari cara menerima input dan menampilkan output menggunakan cin dan cout, melakukan operasi aritmatika, hingga penggunaan percabangan seperti if-else dan switch-case untuk pengambilan keputusan. Selain itu, saya juga memahami cara menggunakan perulangan for, while, dan do-while untuk mengulang proses tertentu, serta membuat program yang lebih kompleks seperti mengonversi angka menjadi kata dan menampilkan pola angka dengan nested loop. Praktikum ini membantu memperkuat pemahaman logika pemrograman dan penerapannya dalam menyelesaikan masalah sederhana.

## Referensi
[1] Wahana Komputer. (2019). Pemrograman C++ untuk Pemula. Yogyakarta: Andi Offset.
[2] Hidayat, T. (2021). “Pengenalan IDE dan Fungsinya dalam Pemrograman.” Jurnal Teknologi dan Sistem Komputer, 9(2), 45–52.
[3] Purnomo, B. (2020). Belajar Dasar-Dasar C++ dan OOP. Jakarta: Elex Media Komputindo.
<br>...
