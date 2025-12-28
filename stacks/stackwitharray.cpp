
// Stack Implementation using array

#include<iostream>
using namespace std;

class Stack {
    // Implementation using array

    int* arr;   // Dynamic array banayenge stack ke elements store karne ke liye
    int size;   // Stack ka maximum size
    int top;    // Top pointer jo stack ke last element ko point karega

public:
    // Constructor
    Stack(int s) {
        size = s;               // Step 1: Stack ka size initialize karo
        top = -1;               // Step 2: Top ko -1 set karo (iska matlab stack abhi empty hai)
        arr = new int[s];       // Step 3: Dynamic memory allocate karo 's' elements ke liye
    }

    // Push function (element ko stack me dalna)
    void push(int value) {
        if (top == size - 1) {   // Agar top last index pe hai toh stack full hai
            cout << "overflow\n";  
            return;
        } else {
            top++;               // Top ko ek step aage badhao
            arr[top] = value;    // Naya value insert karo top position pe
            cout << "Pushed " << value << " into the stack\n";
        }
    }

    // Pop function (element ko stack se nikalna)
    void pop() {
        if (top == -1) {         // Agar top -1 hai toh stack empty hai
            cout << "stack underflow\n";
        } else {
            cout << "popped " << arr[top] << " from the stack\n";
            top--;               // Top ko ek step peeche le jao
        }
    }

    // Peek function (top element dekhna bina nikalne ke)
    int peek() {
        if (top == -1) {         // Agar stack empty hai
            cout << "stack is empty\n";
            return -1;
        } else {
            return arr[top];     // Top element return karo
        }
    }

    // IsEmpty function (check karo stack empty hai ya nahi)
    bool IsEmpty() {
        return top == -1;        // Agar top -1 hai toh stack empty hai
    }

    // IsSSize function (kitne elements present hain stack me)
    int IsSSize() {
        return top + 1;          // Top + 1 = total elements
    }
};

int main() {
    Stack s(5);       // Ek stack banaya jiska size 5 hai

    s.push(5);        // Push 5
    s.push(6);        // Push 6
    s.push(7);        // Push 7
    s.push(8);        // Push 8

    s.pop();          // Pop last element (8)
    s.pop();          // Pop next element (7)

    cout << s.peek() << endl;  // Ab top element 6 hoga

    // Extra check
    cout << "Is stack empty? " << (s.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Current size of stack: " << s.IsSSize() << endl;

    return 0;
}