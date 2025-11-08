#include <iostream>
#include <queue>
using namespace std;
void sortQueue(queue<int>& q) {
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int minIndex = -1;
        int minValue = INT_MAX;
        int n = q.size();
        for (int j = 0; j < n; j++) {
            int curr = q.front();
            q.pop();

            if (curr < minValue && j < n - i) { 
                minValue = curr;
                minIndex = j;
            }
            q.push(curr);
        }

        for (int j = 0; j < n; j++) {
            int curr = q.front();
            q.pop();
            if (j != minIndex)
                q.push(curr);
        }
        q.push(minValue);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}