#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }  // Constructor initializes empty stack

    // Push operation
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    // Peek operation
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}