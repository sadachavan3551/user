#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    int st[50];
    int top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        top++;
        st[top] = x;
    }

    int pop() {
        int x = st[top];
        top--;
        return x;
    }
};

int main() {
    Stack s;
    string exp;
    int a, b, ans;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }
        else {
            b = s.pop();
            a = s.pop();

            if (ch == '+') {
                ans = a + b;
            }
            else if (ch == '-') {
                ans = a - b;
            }
            else if (ch == '*') {
                ans = a * b;
            }
            else if (ch == '/') {
                ans = a / b;
            }

            s.push(ans);
        }
    }

    cout << "Answer is: " << s.pop();

    return 0;
}
