#include <iostream>
using namespace std;

int main() {
    int product[50];
    int n, key;
    int found = 0;

    cout << "Enter number of products: ";
    cin >> n;

    cout << "Enter product ids: ";
    for (int i = 0; i < n; i++) {
        cin >> product[i];
    }

    cout << "Enter product id to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (product[i] == key) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        cout << "Product found";
    }
    else {
        cout << "Product not found";
    }

    return 0;
}
