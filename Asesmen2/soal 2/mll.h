#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

typedef struct childNode* adrChild;
typedef struct parentNode* adrParent;

/* ===== CHILD ===== */
struct childNode {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    adrChild next;
    adrChild prev;
};

struct listChild {
    adrChild first;
    adrChild last;
};

/* ===== PARENT ===== */
struct parentNode {
    string idGenre;
    string namaGenre;
    adrParent next;
    adrParent prev;
    listChild child;
};

struct listParent {
    adrParent first;
    adrParent last;
};

/* ===== ADT ===== */
void createListParent(listParent &LP);
void createListChild(listChild &LC);

adrParent alokasiNodeParent(string id, string nama);
adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void dealokasiNodeParent(adrParent &P);
void dealokasiNodeChild(adrChild &C);

void insertFirstParent(listParent &LP, adrParent P);
void insertLastChild(listChild &LC, adrChild C);

void deleteAfterParent(listParent &LP, string idPrev);
void hapusListChild(listChild &LC);

void printStrukturMLL(listParent LP);
void searchFilmByRatingRange(listParent LP, float min, float max);

#endif
