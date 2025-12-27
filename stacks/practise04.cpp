#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    stack<char> s; // stack banaya

    for (char ch : expr) {
        // Agar opening bracket hai toh stack me push karo
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // Agar closing bracket hai toh check karo
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false; // agar stack empty hai -> unbalanced

            char top = s.top();
            s.pop();

            // Matching check
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    // Agar stack empty hai -> balanced
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced Parentheses ✅" << endl;
    else
        cout << "Not Balanced ❌" << endl;

    return 0;
}