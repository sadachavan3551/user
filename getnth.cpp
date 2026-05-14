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

void getNth() {
    int index;
    cout << "Enter index: ";
    cin >> index;

    Node* ptr = head;
    int count = 0;

    while (ptr != NULL) {
        if (count == index) {
            cout << "Data at index " << index << " is: " << ptr->data << endl;
            return;
        }

        count++;
        ptr = ptr->next;
    }

    cout << "Invalid index" << endl;
}

int main() {
    create_list();
    display();
    getNth();

    return 0;
}
