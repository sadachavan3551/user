#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue() {
    Node* NN = new Node;

    cout << "Enter data: ";
    cin >> NN->data;

    NN->next = NULL;

    if (front == NULL && rear == NULL) {
        front = NN;
        rear = NN;
    }
    else {
        rear->next = NN;
        rear = NN;
    }

    cout << "Element inserted in queue" << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    cout << "Deleted element is: " << temp->data << endl;
    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* ptr = front;

    cout << "Queue elements: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- Queue Using Linked List ---";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exiting";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
