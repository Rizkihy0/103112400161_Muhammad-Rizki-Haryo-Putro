#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
};

void insert(Node*& head, const string& name) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteName(Node*& head, const string& name) {
    if (head == nullptr) return;

    if (head->name == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->name != name) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }
}

void list(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

int hitungGenap(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->name.length() % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = nullptr;
    int choice;
    string name;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, name);
                insert(head, name);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                getline(cin, name);
                deleteName(head, name);
                break;

            case 3:
                list(head);
                break;

            case 4:
                cout << "Jumlah nama dengan huruf genap: " << hitungGenap(head) << endl;
                break;

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}