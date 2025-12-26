#include<iostream>
#include<climits>
using namespace std;

// Node class for linked list stack
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// Custom Stack class
class Stack {
    Node* head;
    int currSize;

public:
    Stack() {
        head = NULL;
        currSize = 0;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        currSize++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return INT_MIN;
        }
        Node* temp = head;
        int poppedElement = temp->data;
        head = head->next;
        delete temp;
        currSize--;
        return poppedElement;
    }

    int top() {
        if (isEmpty()) return INT_MIN;
        return head->data;
    }
};

// Function to evaluate postfix expression
int evaluatePostfix(string expr) {
    Stack st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Agar digit hai toh stack me push karo
        if (isdigit(ch)) {
            st.push(ch - '0');   // char ko int me convert karna
        }
        else {
            // Operator mila toh do elements pop karo
            int val2 = st.pop();
            int val1 = st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.pop();   // final result
}

// ---------------- Main Function ----------------
int main() {
    string expr = "23*54*+9-";   // postfix expression
    cout << "Postfix Expression: " << expr << endl;
    cout << "Evaluation Result: " << evaluatePostfix(expr) << endl;
    return 0;
}