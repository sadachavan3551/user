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

    cout << "Linked List: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void find_middle() {
    if (head == NULL) {
        cout << "List is empty";
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
    for (int i = 1; i < middle; i++) {
        ptr = ptr->next;
    }

    cout << "Middle node is: " << ptr->data << endl;
}

int main() {
    create_list();
    display();
    find_middle();

    return 0;
}
