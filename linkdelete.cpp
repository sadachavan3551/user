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
    Node* ptr = head;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Linked List: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void delete_middle() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Middle node deleted" << endl;
        return;
    }

    int count = 0;
    Node* ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    int middle = count / 2 + 1;

    ptr = head;

    for (int i = 1; i < middle - 1; i++) {
        ptr = ptr->next;
    }

    Node* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;

    cout << "Middle node deleted" << endl;
}

int main() {
    create_list();

    cout << "\nBefore deleting middle node:" << endl;
    display();

    delete_middle();

    cout << "\nAfter deleting middle node:" << endl;
    display();

    return 0;
}
