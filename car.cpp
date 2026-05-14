#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string name;
    int price;

    void setd() {
        cout << "Enter car name: ";
        cin >> name;
        cout << "Enter price: ";
        cin >> price;
    }

    void getd() {
        cout << name << " " << price << endl;
    }
};

int main() {
    Car c[50];
    int n;

    cout << "Enter number of cars: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        c[i].setd();
    }

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (c[j].price < c[min].price) {
                min = j;
            }
        }

        Car temp = c[i];
        c[i] = c[min];
        c[min] = temp;
    }

    cout << "Cars sorted by price:" << endl;

    for (int i = 0; i < n; i++) {
        c[i].getd();
    }

    return 0;
}
