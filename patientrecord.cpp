#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int age;
    string disease;

    void setd() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter disease: ";
        cin >> disease;
    }

    void getd() {
        cout << name << " " << age << " " << disease << endl;
    }
};

int main() {
    Patient p[50];
    int n;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i].setd();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].name > p[j + 1].name) {
                Patient temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    cout << "Patients sorted by name:" << endl;

    for (int i = 0; i < n; i++) {
        p[i].getd();
    }

    return 0;
}
