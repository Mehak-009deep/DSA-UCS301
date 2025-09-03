#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the brackets are matching pair
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check for balanced parentheses
bool areParenthesesBalanced(const string& expr) {
    stack<char> s;

    for (char ch : expr) {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;  // Mismatched or unbalanced
            }
            s.pop();  // Matched pair found
        }
    }

    return s.empty();  // If stack is empty, all brackets matched
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does NOT have balanced parentheses." << endl;
    }

    return 0;
}