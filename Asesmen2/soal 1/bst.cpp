#include "bst.h"

void createTree(BST &T) {
    T.root = NULL;
}

bool isEmpty(BST T) {
    return T.root == NULL;
}

adrBST newNode(string nama, float berat, string tier) {
    adrBST P = new NodeBST;
    P->namaMember = nama;
    P->beratBadan = berat;
    P->tierMember = tier;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertNode(BST &T, adrBST P) {
    if (isEmpty(T)) {
        T.root = P;
    } else {
        adrBST Q = T.root;
        while (true) {
            if (P->beratBadan < Q->beratBadan) {
                if (Q->left == NULL) {
                    Q->left = P;
                    break;
                }
                Q = Q->left;
            } else {
                if (Q->right == NULL) {
                    Q->right = P;
                    break;
                }
                Q = Q->right;
            }
        }
    }
}

adrBST searchByBeratBadan(BST T, float berat) {
    adrBST P = T.root;
    while (P != NULL) {
        if (P->beratBadan == berat)
            return P;
        else if (berat < P->beratBadan)
            P = P->left;
        else
            P = P->right;
    }
    return NULL;
}

adrBST mostLeft(BST T) {
    adrBST P = T.root;
    if (P == NULL) return NULL;
    while (P->left != NULL)
        P = P->left;
    return P;
}

adrBST mostRight(BST T) {
    adrBST P = T.root;
    if (P == NULL) return NULL;
    while (P->right != NULL)
        P = P->right;
    return P;
}

void inOrder(adrBST root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

void printNode(adrBST P) {
    cout << "Nama Member : " << P->namaMember << endl;
    cout << "Berat Badan : " << P->beratBadan << endl;
    cout << "Tier Member : " << P->tierMember << endl;
}

adrBST getParent(BST T, float berat) {
    adrBST parent = NULL;
    adrBST current = T.root;

    while (current != NULL && current->beratBadan != berat) {
        parent = current;
        if (berat < current->beratBadan)
            current = current->left;
        else
            current = current->right;
    }
    return parent;
}