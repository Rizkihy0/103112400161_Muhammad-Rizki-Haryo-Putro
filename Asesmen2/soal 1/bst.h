#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

typedef struct NodeBST* adrBST;

struct NodeBST {
    string namaMember;
    float beratBadan;
    string tierMember;
    adrBST left;
    adrBST right;
};

struct BST {
    adrBST root;
};

void createTree(BST &T);
bool isEmpty(BST T);
adrBST newNode(string nama, float berat, string tier);
void insertNode(BST &T, adrBST P);
adrBST searchByBeratBadan(BST T, float berat);
adrBST mostLeft(BST T);
adrBST mostRight(BST T);
void inOrder(adrBST root);
void printNode(adrBST P);
adrBST getParent(BST T, float berat);

#endif
