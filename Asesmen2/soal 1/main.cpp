#include "bst.h"

int main() {
    BST T;
    createTree(T);

    insertNode(T, newNode("Rizkina Azizah", 60, "Basic"));
    insertNode(T, newNode("Hakan Ismail", 50, "Bronze"));
    insertNode(T, newNode("Olivia Saevali", 65, "Silver"));
    insertNode(T, newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(T, newNode("Gamel Al Ghifari", 56, "Platinum"));
    insertNode(T, newNode("Mutiara Fauziah", 52, "Bronze"));
    insertNode(T, newNode("Hanif Al Faiz", 70, "Basic"));
    insertNode(T, newNode("Davi Ilyas", 68, "Silver"));
    insertNode(T, newNode("Abdad Mubarak", 81, "Gold"));

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(T.root);
    cout << endl << endl;

    cout << "Node MostLeft : " << mostLeft(T)->beratBadan << endl;
    cout << "Node MostRight: " << mostRight(T)->beratBadan << endl << endl;

    float cari = 70;
    adrBST found = searchByBeratBadan(T, cari);

    if (found != NULL) {
        cout << "=== Data ditemukan dalam BST! ===" << endl;
        printNode(found);

        adrBST parent = getParent(T, cari);
        if (parent != NULL) {
            cout << "\n--- Data Parent ---" << endl;
            printNode(parent);
        }

        if (found->left != NULL) {
            cout << "\n--- Data Child Kiri ---" << endl;
            printNode(found->left);
        }

        if (found->right != NULL) {
            cout << "\n--- Data Child Kanan ---" << endl;
            printNode(found->right);
        }
    }

    return 0;
}