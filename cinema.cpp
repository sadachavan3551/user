#include <iostream>
using namespace std;

int main() {
    int seat[50];
    int n, key;
    int L, R, M;
    int found = 0;

    cout << "Enter number of seats: ";
    cin >> n;

    cout << "Enter sorted seat numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> seat[i];
    }

    cout << "Enter chosen seat: ";
    cin >> key;

    L = 0;
    R = n - 1;

    while (L <= R) {
        M = (L + R) / 2;

        if (key == seat[M]) {
            found = 1;
            break;
        }
        else if (key > seat[M]) {
            L = M + 1;
        }
        else {
            R = M - 1;
        }
    }

    if (found == 1) {
        cout << "Seat Available";
    }
    else {
        cout << "Already Booked";
    }

    return 0;
}
