#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string publication;
    int price;

    void setd() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter author: ";
        cin >> author;
        cout << "Enter publication: ";
        cin >> publication;
        cout << "Enter price: ";
        cin >> price;
    }

    void getd() {
        cout << title << " " << author << " " << publication << " " << price << endl;
    }
};

int main() {
    Book b[50];
    int n;
    string key;
    int found = 0;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        b[i].setd();
    }

    cout << "Enter author to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (b[i].author == key) {
            b[i].getd();
            found = 1;
        }
    }

    if (found == 0) {
        cout << "Book not found";
    }

    return 0;
}
