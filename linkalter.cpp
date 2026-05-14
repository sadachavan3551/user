#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;

void create_list(Node*& head) {
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

void display(Node* head) {
    Node* ptr = head;

    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }

    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

void alternate_insert() {
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* temp1;
    Node* temp2;

    while (ptr1 != NULL && ptr2 != NULL) {
        temp1 = ptr1->next;
        temp2 = ptr2->next;

        ptr1->next = ptr2;
        ptr2->next = temp1;

        ptr1 = temp1;
        ptr2 = temp2;
    }

    head2 = ptr2;
}

int main() {
    cout << "Create first linked list" << endl;
    create_list(head1);

    cout << "\nCreate second linked list" << endl;
    create_list(head2);

    cout << "\nFirst list before insertion: ";
    display(head1);

    cout << "Second list before insertion: ";
    display(head2);

    alternate_insert();

    cout << "\nFirst list after alternate insertion: ";
    display(head1);

    cout << "Second list after alternate insertion: ";
    display(head2);

    return 0;
}
