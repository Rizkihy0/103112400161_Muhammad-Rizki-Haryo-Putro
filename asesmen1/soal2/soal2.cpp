#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

void insertLast(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteLast(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
}

void viewList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList(Node*& head) {
    if (head == nullptr) return;

    Node* current = head;
    Node* temp = nullptr;
    
    // Reverse the pointers
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertLast(head, value);
                break;

            case 2:
                deleteLast(head);
                break;

            case 3:
                viewList(head);
                break;

            case 4:
                reverseList(head);
                cout << "List setelah di-reverse: ";
                viewList(head);
                break;

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}