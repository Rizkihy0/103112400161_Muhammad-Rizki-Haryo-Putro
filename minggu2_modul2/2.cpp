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