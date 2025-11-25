#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

bool isEmpty(QueueEkspedisi& Q) {
    return (Q.Head == -1);
}

bool isFull(QueueEkspedisi& Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi& Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enqueue(QueueEkspedisi& Q, Paket p) {
    if (isFull(Q)) {
        cout << "Queue is full!" << endl;
    } else {
        if (Q.Head == -1) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = p;
    }
}

void dequeue(QueueEkspedisi& Q) {
    if (isEmpty(Q)) {
        cout << "Queue is empty!" << endl;
    } else {
        for (int i = 0; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
        if (Q.Tail == -1) {
            Q.Head = -1;
        }
    }
}

void viewQueue(QueueEkspedisi& Q) {
    if (isEmpty(Q)) {
        cout << "Queue is empty!" << endl;
    } else {
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << "KodeResi: " << Q.dataPaket[i].KodeResi
                 << ", NamaPengirim: " << Q.dataPaket[i].NamaPengirim
                 << ", BeratBarang: " << Q.dataPaket[i].BeratBarang
                 << ", Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        }
    }
}

float totalBiayaPengiriman(QueueEkspedisi& Q) {
    float totalBiaya = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBiaya += Q.dataPaket[i].BeratBarang * 8250;
    }
    return totalBiaya;
}
