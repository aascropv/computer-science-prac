#include <iostream>
using namespace std;

// Function to find pairs with the given target sum using pointer manipulation
void findPairs(int* arr, int n, int target) {
    int* ptr1;
    int* ptr2;
    bool found = false;

    cout << "Pairs found:" << endl;

    for (int i = 0; i < n; i++) {
        ptr1 = arr + i;
        for (int j = i + 1; j < n; j++) {
            ptr2 = arr + j;
            if (*ptr1 + *ptr2 == target) { // found pair
                // cout pairs from smaller to larger
                if (*ptr1 < *ptr2) cout << "(" << *ptr1 << ", " << *ptr2 << ")"<< endl;
                else cout << "(" << *ptr2 << ", " << *ptr1 << ")" << endl;
                found = true;
            }
        }
    }
    if (!found) { // if not found
        cout << "No pairs found." << endl;
    }
}

// Function to sort the array using Bubble Sort
void getResult(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {   //bubble sort array from smallest to largest
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 2 || n > 10) {
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < -10 || arr[i] > 10) {
            return 1;
        }
    }

    int target;
    cin >> target;

    findPairs(arr, n, target);

    getResult(arr, n);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}