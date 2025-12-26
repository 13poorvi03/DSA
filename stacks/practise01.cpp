#include<iostream>
#include<climits>
using namespace std;

// Node class for linked list
class Node {
public:
    char data;      // har node ek character store karega
    Node* next;

    Node(char d) {
        this->data = d;
        this->next = NULL;
    }
};

// Stack class (linked list ke through)
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

    void push(char data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        currSize++;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';   // empty case
        }
        Node* temp = head;
        char poppedElement = temp->data;
        head = head->next;
        delete temp;
        currSize--;
        return poppedElement;
    }

    char top() {
        if (isEmpty()) return '\0';
        return head->data;
    }
};

// Function to check balanced parentheses
bool isBalanced(string expr) {
    Stack st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Agar opening bracket hai toh push karo
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // Agar closing bracket hai toh check karo
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) return false;   // koi opening bracket hi nahi hai

            char topChar = st.pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;   // mismatch case
            }
        }
    }

    return st.isEmpty();   // agar stack empty hai toh balanced hai
}

// ---------------- Main Function ----------------
int main() {
    string expr1 = "((a+b)*c)";
    string expr2 = "((a+b)";

    cout << expr1 << " -> " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " -> " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}