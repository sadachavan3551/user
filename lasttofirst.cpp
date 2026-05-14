#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void create_list() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Node* NN = new Node;

        cout << "Enter data: ";
        cin >> NN->data;

        NN->next = NULL;

        if (head == NULL) {
            head = NN;
        }
        else {
            Node* ptr = head;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }

            ptr->next = NN;
        }
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* ptr = head;

    cout << "Linked List: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

void move_last_to_front() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == NULL) {
        cout << "Only one node, no change needed" << endl;
        return;
    }

    Node* prev = NULL;
    Node* last = head;

    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = head;
    head = last;

    cout << "Last node moved to front" << endl;
}

int main() {
    create_list();

    cout << "\nBefore moving last node:" << endl;
    display();

    move_last_to_front();

    cout << "\nAfter moving last node to front:" << endl;
    display();

    return 0;
}
