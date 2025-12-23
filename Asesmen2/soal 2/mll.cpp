#include "mll.h"

/* CREATE */
void createListParent(listParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void createListChild(listChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}

/* ALOKASI */
adrParent alokasiNodeParent(string id, string nama) {
    adrParent P = new parentNode;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->child);
    return P;
}

adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    adrChild C = new childNode;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

/* DEALOKASI */
void dealokasiNodeParent(adrParent &P) {
    delete P;
    P = NULL;
}

void dealokasiNodeChild(adrChild &C) {
    delete C;
    C = NULL;
}

/* INSERT */
void insertFirstParent(listParent &LP, adrParent P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(listChild &LC, adrChild C) {
    if (LC.first == NULL) {
        LC.first = LC.last = C;
    } else {
        LC.last->next = C;
        C->prev = LC.last;
        LC.last = C;
    }
}

/* DELETE CHILD */
void hapusListChild(listChild &LC) {
    adrChild C;
    while (LC.first != NULL) {
        C = LC.first;
        LC.first = C->next;
        dealokasiNodeChild(C);
    }
    LC.last = NULL;
}

/* DELETE AFTER PARENT */
void deleteAfterParent(listParent &LP, string idPrev) {
    adrParent P = LP.first;
    while (P != NULL && P->idGenre != idPrev)
        P = P->next;

    if (P != NULL && P->next != NULL) {
        adrParent del = P->next;

        hapusListChild(del->child);

        P->next = del->next;
        if (del->next != NULL)
            del->next->prev = P;
        else
            LP.last = P;

        dealokasiNodeParent(del);
    }
}

void printStrukturMLL(listParent LP) {
    adrParent P = LP.first;
    int no = 1;

    while (P != NULL) {
        cout << "=== Parent " << no++ << " ===" << endl;
        cout << "ID Genre : " << P->idGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;

        adrChild C = P->child.first;
        int i = 1;
        while (C != NULL) {
            cout << "- Child " << i++ << " :" << endl;
            cout << "  ID Film : " << C->idFilm << endl;
            cout << "  Judul Film : " << C->judulFilm << endl;
            cout << "  Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "  Tahun Tayang : " << C->tahunTayang << endl;
            cout << "  Rating Film : " << C->ratingFilm << endl;
            C = C->next;
        }
        cout << "------------------------" << endl;
        P = P->next;
    }
}

void searchFilmByRatingRange(listParent LP, float min, float max) {
    adrParent P = LP.first;
    int posParent = 1;

    while (P != NULL) {
        adrChild C = P->child.first;
        int posChild = 1;

        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "Data Film ditemukan pada list child dari node parent "
                     << P->namaGenre << " pada posisi ke-" << posChild << endl;

                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "ID Film : " << C->idFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;

                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "==========================" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}