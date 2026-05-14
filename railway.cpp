#include <iostream>
#include <string>
using namespace std;

class Railway {
public:
    string station1;
    string station2;
    int trainId;
    string trainName;
    string time;

    void setd() {
        cout << "Enter first station: ";
        cin >> station1;

        cout << "Enter second station: ";
        cin >> station2;

        cout << "Enter train id: ";
        cin >> trainId;

        cout << "Enter train name: ";
        cin >> trainName;

        cout << "Enter schedule time: ";
        cin >> time;
    }

    void getd() {
        cout << station1 << " " << station2 << " "
             << trainId << " " << trainName << " "
             << time << endl;
    }
};

int main() {
    Railway r[50];
    int n;

    cout << "Enter number of railway records: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        r[i].setd();
    }

    cout << "Railway records are:" << endl;

    for (int i = 0; i < n; i++) {
        r[i].getd();
    }

    return 0;
}
