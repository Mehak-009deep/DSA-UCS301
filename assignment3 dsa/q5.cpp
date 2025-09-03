#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> s;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        // If token is an operand (number)
        if (isdigit(token[0]) || 
            (token.length() > 1 && token[0] == '-' && isdigit(token[1]))) {
            s.push(stoi(token));
        }
        // If token is an operator
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            if (s.size() < 2) {
                cout << "Error: Invalid postfix expression.\n";
                return 0;
            }

            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;
            else if (token == "^") result = pow(a, b);

            s.push(result);
        }
        else {
            cout << "Error: Unknown token '" << token << "'.\n";
            return 0;
        }
    }

    if (s.size() != 1) {
        cout << "Error: Invalid postfix expression.\n";
        return 0;
    }

    return s.top();
}

int main() {
    string postfix;

    cout << "Enter a postfix expression (space-separated, e.g., '5 3 + 2 *'): ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}