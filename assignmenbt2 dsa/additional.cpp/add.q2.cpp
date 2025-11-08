#include <iostream>
using namespace std;
bool isSubstring(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2) return false;

    for (int i = 0; i <= n2 - n1; i++) {
        int j;
        for (j = 0; j < n1; j++) {
            if (s2[i + j] != s1[j]) break;
        }
        if (j == n1) return true;
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.length();
    bool possible = false;

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);
            if ((isSubstring(A, B) && isSubstring(A, C)) ||
                (isSubstring(B, A) && isSubstring(B, C)) ||
                (isSubstring(C, A) && isSubstring(C, B))) {
                possible = true;
                cout << "Split possible: " << A << " | " << B << " | " << C << endl;
            }
        }
    }

    if (!possible) {
        cout << "Not possible to split." << endl;
    }

    return 0;
}