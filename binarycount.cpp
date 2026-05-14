#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            ans = mid;
            high = mid - 1;  
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            ans = mid;
            low = mid + 1;   
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, key;
    int arr[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number to count: ";
    cin >> key;

    int first = firstOcc(arr, n, key);
    int last = lastOcc(arr, n, key);

    if (first == -1) {
        cout << "Element not found";
    }
    else {
        int count = last - first + 1;
        cout << key << " occurs " << count << " times";
    }

    return 0;
}
