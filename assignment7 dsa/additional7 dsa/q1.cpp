#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    // Step 1: Find the maximum element (to know count array size)
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // Step 2: Create count array of size maxVal+1 and initialize to 0
    vector<int> count(maxVal + 1, 0);

    // Step 3: Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Modify count array — cumulative sum
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Create output array
    vector<int> output(n);

    // Step 6: Build the output array (stable sorting)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 7: Copy output back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (non-negative integers): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}

/*
---------------- SAMPLE INPUT ----------------
Enter number of elements: 8
Enter elements: 4 2 2 8 3 3 1 7

---------------- SAMPLE OUTPUT ----------------
Sorted Array: 1 2 2 3 3 4 7 8
*/
