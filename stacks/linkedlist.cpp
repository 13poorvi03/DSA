#include<iostream>
#include<climits>   // INT_MIN ke liye (underflow case mein return karne ke liye)
using namespace std;

// ---------------- Node Class ----------------
class Node {
public:
    int data;       // har node mein ek integer data hoga
    Node* next;     // pointer jo next node ko point karega

    // Constructor: jab naya node banega tab data set hoga aur next = NULL hoga
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// ---------------- Stack Class (Linked List ke through) ----------------
class Stack {
    Node* head;      // stack ka top node (linked list ka head)
    int capacity;    // stack ki maximum size (limit)
    int currSize;    // abhi stack mein kitne elements hai

public:
    // Constructor: jab stack object banega
    Stack(int c) {
        this->capacity = c;   // max size set karo
        this->currSize = 0;   // initially stack empty hai
        head = NULL;          // head NULL matlab koi node nahi hai
    }

    // Stack empty hai ya nahi check karna
    bool isEmpty() {
        return this->head == NULL;   // agar head NULL hai toh stack empty hai
    }

    // Stack full hai ya nahi check karna
    bool isFull() {
        return this->currSize == this->capacity;   // agar currSize == capacity hai toh full hai
    }

    // ---------------- Push Operation ----------------
    void push(int data) {
        if (isFull()) {   // agar stack full hai toh overflow
            cout << "Overflow\n";
            return;
        }
        // naya node banate hain
        Node* new_node = new Node(data);

        // naya node ka next current head ko point karega
        new_node->next = this->head;

        // head ko update karenge naya node pe (top shift ho gaya)
        this->head = new_node;

        // size badha do
        this->currSize++;
    }

    // ---------------- Pop Operation ----------------
    int pop() {
        if (isEmpty()) {   // agar stack empty hai toh underflow
            cout << "Underflow\n";
            return INT_MIN;
        }

        // temporary pointer top node ko store karega
        Node* temp = head;

        // top element ka data store karo
        int poppedElement = temp->data;

        // head ko next node pe shift kar do (top remove ho gaya)
        head = head->next;

        // purana top node delete kar do (memory free)
        delete temp;

        // size kam kar do
        this->currSize--;

        // popped element return karo
        return poppedElement;
    }

    // ---------------- Top Operation ----------------
    int top() {
        if (isEmpty()) {   // agar stack empty hai toh underflow
            cout << "Underflow\n";
            return INT_MIN;
        }
        // head ka data hi top element hai
        return head->data;
    }

    // ---------------- Size Operation ----------------
    int size() {
        return this->currSize;   // abhi kitne elements stack mein hai
    }
};

// ---------------- Main Function ----------------
int main() {
    Stack st(5);   // capacity 5 ka stack banaya

    // Push operations
    st.push(10);   // stack = [10]
    st.push(20);   // stack = [20, 10]
    st.push(30);   // stack = [30, 20, 10]

    // Top element dekhna
    cout << "Top element: " << st.top() << "\n";   // output: 30

    // Pop operation
    cout << "Popped: " << st.pop() << "\n";        // output: 30, stack = [20, 10]

    // Top element dobara dekhna
    cout << "Top element: " << st.top() << "\n";   // output: 20

    // Current size check karna
    cout << "Current size: " << st.size() << "\n"; // output: 2

    return 0;
}