#include <iostream>
using namespace std;

// ---------------- SELECTION SORT ----------------
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

// ---------------- INSERTION SORT ----------------
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------------- BUBBLE SORT ----------------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// ---------------- MERGE SORT ----------------
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    while (i < n1)
        arr[k++] = a[i++];

    while (j < n2)
        arr[k++] = b[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ---------------- QUICK SORT ----------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------- PRINT FUNCTION ----------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "\nChoose Sorting Technique:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: selectionSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        case 3: bubbleSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        case 5: quickSort(arr, 0, n - 1); break;
        default: 
            cout << "Invalid choice!";
            return 0;
    }

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}

/*
---------------- SAMPLE INPUT ----------------
Enter number of elements: 5
Enter elements: 7 2 9 1 5

Choose Sorting Technique:
1. Selection Sort
2. Insertion Sort
3. Bubble Sort
4. Merge Sort
5. Quick Sort
Enter choice: 4

---------------- SAMPLE OUTPUT ----------------
Sorted Array: 1 2 5 7 9
*/
