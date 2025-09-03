#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse a string using a stack
string reverseStringUsingStack(const string& input) {
    stack<char> s;
    string reversed = "";

    // Push each character onto the stack
    for (char ch : input) {
        s.push(ch);
    }

    // Pop characters from the stack to reverse the string
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);  // to include spaces

    string result = reverseStringUsingStack(input);

    cout << "Reversed string: " << result << endl;

    return 0;
}