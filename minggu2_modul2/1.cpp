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