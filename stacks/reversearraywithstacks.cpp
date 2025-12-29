

// Stack Implementation using array for reversing a string

#include<iostream>
#include<string>
using namespace std;

class Stack {
    // Implementation using array

    char* arr;   // Dynamic array banayenge stack ke characters store karne ke liye
    int size;    // Stack ka maximum size
    int top;     // Top pointer jo stack ke last element ko point karega

public:
    // Constructor
    Stack(int s) {
        size = s;               // Step 1: Stack ka size initialize karo
        top = -1;               // Step 2: Top ko -1 set karo (iska matlab stack abhi empty hai)
        arr = new char[s];      // Step 3: Dynamic memory allocate karo 's' characters ke liye
    }

    // Push function (character ko stack me dalna)
    void push(char value) {
        if (top == size - 1) {   // Agar top last index pe hai toh stack full hai
            cout << "overflow\n";  
            return;
        } else {
            top++;               // Top ko ek step aage badhao
            arr[top] = value;    // Naya character insert karo top position pe
        }
    }

    // Pop function (character ko stack se nikalna)
    char pop() {
        if (top == -1) {         // Agar top -1 hai toh stack empty hai
            cout << "stack underflow\n";
            return '\0';
        } else {
            char val = arr[top]; // Top element store karo
            top--;               // Top ko ek step peeche le jao
            return val;          // Popped character return karo
        }
    }

    // IsEmpty function (check karo stack empty hai ya nahi)
    bool IsEmpty() {
        return top == -1;        // Agar top -1 hai toh stack empty hai
    }
};

// Function to reverse a string using Stack
string reverseString(string str) {
    Stack s(str.length());   // Stack banaya jiska size string ke length ke barabar hai

    // Step 1: Har character ko stack me push karo
    for (char c : str) {
        s.push(c);
    }

    // Step 2: Har character ko pop karke nayi string me dal do
    string reversed = "";
    while (!s.IsEmpty()) {
        reversed += s.pop();
    }

    return reversed;
}

int main() {
    string str = "hello";   // Input string
    cout << "Original string: " << str << endl;

    string result = reverseString(str);
    cout << "Reversed string: " << result << endl;

    return 0;
}

















// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// string reverseString(const string& str) {
//     stack<char> st;

//     // Step 1: Push all characters into the stack
//     for (char c : str) {
//         st.push(c);
//     }

//     // Step 2: Pop characters from stack to build reversed string
//     string reversed = "";
//     while (!st.empty()) {
//         reversed += st.top();
//         st.pop();
//     }

//     return reversed;
// }

// int main() {
//     string str = "hello";   // Input string
//     cout << "Original string: " << str << endl;

//     string result = reverseString(str);
//     cout << "Reversed string: " << result << endl;

//     return 0;
// }