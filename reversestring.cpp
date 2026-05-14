#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    char st[50];
    int top;

    Stack() {
        top = -1;
    }

    void push(char ch) {
        top++;
        st[top] = ch;
    }

    char pop() {
        char ch = st[top];
        top--;
        return ch;
    }

    int isEmpty() {
        if (top == -1)
            return 1;
        else
            return 0;
    }
};

int main() {
    Stack s;
    string str, rev = "";

    cout << "Enter string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    while (!s.isEmpty()) {
        rev = rev + s.pop();
    }

    cout << "Original string: " << str << endl;
    cout << "Reverse string: " << rev;

    return 0;
}
