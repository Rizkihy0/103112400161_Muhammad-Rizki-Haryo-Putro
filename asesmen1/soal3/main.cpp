#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

int main() {
    StackMahasiswa stack;
    createStack(stack);

    Mahasiswa m1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa m2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa m3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa m4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Mahasiswa m5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa m6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    push(stack, m1);
    push(stack, m2);
    push(stack, m3);
    push(stack, m4);
    push(stack, m5);
    push(stack, m6);

    cout << "Tampilan stack setelah dimasukkan data mahasiswa:" << endl;
    view(stack);

    pop(stack);
    cout << "\nTampilan stack setelah pop 1x:" << endl;
    view(stack);

    Mahasiswa m7 = {"Heizou", "77777", 99.9, 88.8, 77.7};
    update(stack, 3, m7);
    cout << "\nTampilan stack setelah update:" << endl;
    view(stack);

    cout << "\nSearching mahasiswa dengan NilaiAkhir antara 85.5 sampai 95.5:" << endl;
    searchNilaiAkhir(stack, 85.5, 95.5);

    return 0;
}
