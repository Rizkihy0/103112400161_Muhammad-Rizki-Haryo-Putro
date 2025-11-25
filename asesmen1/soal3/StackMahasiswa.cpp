#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa& S) {
    return (S.Top == -1);
}

bool isFull(StackMahasiswa& S) {
    return (S.Top == MAX - 1);
}

void createStack(StackMahasiswa& S) {
    S.Top = -1;
}

void push(StackMahasiswa& S, Mahasiswa m) {
    if (isFull(S)) {
        cout << "Stack is full!" << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = m;
    }
}

void pop(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Stack is empty!" << endl;
    } else {
        S.Top--;
    }
}

void view(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Stack is empty!" << endl;
    } else {
        for (int i = 0; i <= S.Top; i++) {
            cout << "Nama: " << S.dataMahasiswa[i].Name << ", NIM: " << S.dataMahasiswa[i].NIM 
                 << ", Nilai Tugas: " << S.dataMahasiswa[i].NilaiTugas << ", Nilai UTS: " 
                 << S.dataMahasiswa[i].NilaiUTS << ", Nilai UAS: " << S.dataMahasiswa[i].NilaiUAS << endl;
        }
    }
}

void update(StackMahasiswa& S, int pos, Mahasiswa m) {
    if (pos < 0 || pos > S.Top) {
        cout << "Invalid position!" << endl;
    } else {
        S.dataMahasiswa[pos] = m;
    }
}

void searchNilaiAkhir(StackMahasiswa& S, float min, float max) {
    for (int i = 0; i <= S.Top; i++) {
        float nilaiAkhir = (S.dataMahasiswa[i].NilaiTugas * 0.2) + (S.dataMahasiswa[i].NilaiUTS * 0.4) + (S.dataMahasiswa[i].NilaiUAS * 0.4);
        if (nilaiAkhir >= min && nilaiAkhir <= max) {
            cout << "Nama: " << S.dataMahasiswa[i].Name << ", NIM: " << S.dataMahasiswa[i].NIM
                 << ", Nilai Akhir: " << nilaiAkhir << endl;
        }
    }
}