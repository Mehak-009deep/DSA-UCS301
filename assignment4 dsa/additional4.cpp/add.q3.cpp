#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canSortQueue(queue<int> q) {
    stack<int> s;       
    queue<int> sorted;  
    int n = q.size();
    int nextExpected = 1; 

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        
        if (front == nextExpected) {
            sorted.push(front);
            nextExpected++;
        } else {
          while (!s.empty() && s.top() == nextExpected) {
                sorted.push(s.top());
                s.pop();
                nextExpected++;
            }
            s.push(front);
        }
    }
    while (!s.empty()) {
        if (s.top() != nextExpected)
            return false;
        sorted.push(s.top());
        s.pop();
        nextExpected++;
    }

    return true;
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (canSortQueue(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}