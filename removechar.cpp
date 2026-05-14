#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, result = "";

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    for (int i = 0; i < str1.length(); i++) {
        int found = 0;

        for (int j = 0; j < str2.length(); j++) {
            if (str1[i] == str2[j]) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            result = result + str1[i];
        }
    }

    cout << "Output string: " << result << endl;

    return 0;
}
