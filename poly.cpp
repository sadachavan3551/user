#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;
};

Node* p = NULL;
Node* q = NULL;
Node* r = NULL;

void insert(Node*& head, int c, int pow) {
    Node* NN = new Node;
    NN->coeff = c;
    NN->power = pow;
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

void display(Node* head) {
    Node* ptr = head;

    while (ptr != NULL) {
        cout << ptr->coeff << "x^" << ptr->power;
        ptr = ptr->next;

        if (ptr != NULL) {
            cout << " + ";
        }
    }
    cout << endl;
}

void addPoly() {
    Node* ptr1 = p;
    Node* ptr2 = q;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->power == ptr2->power) {
            insert(r, ptr1->coeff + ptr2->coeff, ptr1->power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->power > ptr2->power) {
            insert(r, ptr1->coeff, ptr1->power);
            ptr1 = ptr1->next;
        }
        else {
            insert(r, ptr2->coeff, ptr2->power);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        insert(r, ptr1->coeff, ptr1->power);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        insert(r, ptr2->coeff, ptr2->power);
        ptr2 = ptr2->next;
    }
}

int main() {
    insert(p, 5, 3);
    insert(p, 4, 2);
    insert(p, 2, 1);
    insert(p, 7, 0);

    insert(q, 3, 3);
    insert(q, 6, 2);
    insert(q, 8, 0);

    cout << "First polynomial: ";
    display(p);

    cout << "Second polynomial: ";
    display(q);

    addPoly();

    cout << "Addition is: ";
    display(r);

    return 0;
}
