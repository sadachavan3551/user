#include <iostream>
using namespace std;

int main() {
    int code[50];
    int n, key;
    int found = 0;

    cout << "Enter number of product codes: ";
    cin >> n;

    cout << "Enter product codes: ";
    for (int i = 0; i < n; i++) {
        cin >> code[i];
    }

    cout << "Enter code to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (code[i] == key) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        cout << "Item Found";
    }
    else {
        cout << "Item Not Found";
    }

    return 0;
}
