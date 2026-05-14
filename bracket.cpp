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

    char peek() {
        return st[top];
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
    string str;
    int flag = 1;

    cout << "Enter bracket string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                flag = 0;
                break;
            }

            char topChar = s.peek();

            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                s.pop();
            }
            else {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1 && s.isEmpty()) {
        cout << "Balanced";
    }
    else {
        cout << "Not Balanced";
    }

    return 0;
}
