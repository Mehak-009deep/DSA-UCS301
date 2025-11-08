#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int count = 0;

    cout << "Pairs with difference " << k << " are:\n";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = arr[i] - arr[j];
            if (diff < 0) diff = -diff; // manual abs()
            if (diff == k) {
                cout << "(" << arr[i] << ", " << arr[j] << ")\n";
                count++;
            }
        }
    }

    cout << "Total pairs with difference " << k << " = " << count << endl;

    return 0;
}