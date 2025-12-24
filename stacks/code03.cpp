#include <iostream>
#include <stack>   // STL stack use karenge
using namespace std;

string reverseString(string str) {
    stack<char> st;   // ek stack banaya jo characters store karega

    // Step 1: har character ko stack me push karo
    for (int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }

    // Step 2: stack se pop karke naya string banao (reverse order me milega)
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();   // top element add karo
        st.pop();               // element remove karo
    }

    return reversed;
}

int main() {
    string s = "hello";
    cout << "Original string: " << s << endl;
    cout << "Reversed string: " << reverseString(s) << endl;
    return 0;
}