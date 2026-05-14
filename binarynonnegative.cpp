#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted distinct non-negative elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0, high = n - 1;
    int ans = n;   

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }

    cout << "Smallest missing non-negative number is: " << ans << endl;

    return 0;
}
