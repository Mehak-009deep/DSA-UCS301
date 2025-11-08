#include <iostream>
#include <queue>
using namespace std;

int countStudentsUnableToEat(int students[], int sandwiches[], int n) {
    queue<int> q; 
    for (int i = 0; i < n; i++)
        q.push(students[i]);

    int index = 0;
    int rotations = 0;

    while (!q.empty() && rotations < q.size()) {
        int front = q.front();
        q.pop();

        if (front == sandwiches[index]) {
           
            index++;
            rotations = 0;
        } else {

            q.push(front);
            rotations++;
        }
    }

    return q.size();  
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = sizeof(students) / sizeof(students[0]);

    int result = countStudentsUnableToEat(students, sandwiches, n);
    cout << result << endl;

    return 0;
}