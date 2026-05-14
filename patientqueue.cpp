#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
    string q[20];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string name) {
        if (rear == 19) {
            cout << "Queue is full" << endl;
        }
        else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            q[rear] = name;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << "Removed patient: " << q[front] << endl;
            front++;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    string name;

    cout << "Enter 5 patient names:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> name;
        q.enqueue(name);
    }

    cout << "Queue after creation:" << endl;
    q.display();

    cout << "Enter 2 new patient names:" << endl;
    for (int i = 0; i < 2; i++) {
        cin >> name;
        q.enqueue(name);
    }

    cout << "Queue after adding patients:" << endl;
    q.display();

    q.dequeue();
    q.dequeue();

    cout << "Queue after removing patients:" << endl;
    q.display();

    return 0;
}
