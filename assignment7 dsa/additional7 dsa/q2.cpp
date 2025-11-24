#include <iostream>
using namespace std;

// Counting Sort used by Radix Sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};  // digits 0–9

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(int arr[], int n) {
    // Find the maximum number
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // Apply counting sort for each digit (1s, 10s, 100s...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
---------------- SAMPLE INPUT ----------------
Enter number of elements: 8
Enter elements: 170 45 75 90 802 24 2 66

---------------- SAMPLE OUTPUT ----------------
Sorted Array: 2 24 45 66 75 90 170 802
*/
