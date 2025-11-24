#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;          // Starting index
    int right = n - 1;     // Ending index

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // If first element is bigger than last, swap indices
        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        // Traverse the middle part
        for (int i = left + 1; i < right; i++) {

            if (arr[i] < arr[minIndex])
                minIndex = i;

            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum at the left end
        swap(arr[left], arr[minIndex]);

        // Correction: If maximum was swapped during min swap
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum at the right end
        swap(arr[right], arr[maxIndex]);

        // Move inward from both ends
        left++;
        right--;
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
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}

/*
---------------- SAMPLE INPUT ----------------
Enter number of elements: 7
Enter elements: 10 2 7 5 9 1 3

---------------- SAMPLE OUTPUT ----------------
Sorted Array: 1 2 3 5 7 9 10
*/
