#ifndef QUEUEPENGIRIMAN_H_INCLUDED
#define QUEUEPENGIRIMAN_H_INCLUDED

#include <string>
using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head = -1;
    int Tail = -1;
};

bool isEmpty(QueueEkspedisi& Q);
bool isFull(QueueEkspedisi& Q);
void createQueue(QueueEkspedisi& Q);
void enqueue(QueueEkspedisi& Q, Paket p);
void dequeue(QueueEkspedisi& Q);
void viewQueue(QueueEkspedisi& Q);
float totalBiayaPengiriman(QueueEkspedisi& Q);

#endif