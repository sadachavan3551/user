#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    string st[50];
    int top;

    Stack() {
        top = -1;
    }

    void push(string page) {
        top++;
        st[top] = page;
    }

    void pop() {
        if (top == -1) {
            cout << "History is empty" << endl;
        }
        else {
            cout << "Back from: " << st[top] << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "History is empty" << endl;
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << st[i] << endl;
            }
        }
    }
};

int main() {
    Stack s;
    string page;
    int n;

    cout << "Enter number of pages visited: ";
    cin >> n;

    cout << "Enter page names:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> page;
        s.push(page);
    }

    cout << "Browser history:" << endl;
    s.display();

    s.pop();

    cout << "History after back operation:" << endl;
    s.display();

    return 0;
}
