#include<iostream>
#include<climits>
using namespace std;

// ---------------- Node Class ----------------
// Linked list ke ek node ko represent karta hai
class Node {
public:
    int data;           // Node ke andar ek integer data store hoga
    Node* next;         // Pointer jo next node ko point karega

    // Constructor: jab naya node banega tab data set hoga aur next = NULL hoga
    Node(int d) {
        this->data = d;     // current node ka data set karo
        this->next = NULL;  // initially next pointer NULL hoga
    }
};

// ---------------- Stack Class (Linked List ke through) ----------------
class Stack {
    Node* head;         // Stack ka top node (linked list ka head)
    int capacity;       // Stack ki maximum size (limit)
    int currSize;       // Abhi stack mein kitne elements hai

public:
    // Constructor: jab stack object banega
    Stack(int c) {
        this->capacity = c;   // max size set karo
        this->currSize = 0;   // initially stack empty hai
        head = NULL;          // head NULL matlab koi node nahi hai
    }

    // Stack empty hai ya nahi check karna
    bool isEmpty() {
        return head == NULL;   // agar head NULL hai toh stack empty hai
    }

    // Stack full hai ya nahi check karna
    bool isFull() {
        return currSize == capacity;   // agar currSize == capacity hai toh full hai
    }

    // ---------------- Push Operation ----------------
    void push(int data) {
        if (isFull()) {   // agar stack full hai toh overflow
            cout << "Overflow\n";
            return;
        }
        Node* new_node = new Node(data);   // naya node banate hain
        new_node->next = head;             // naya node ka next current head ko point karega
        head = new_node;                   // head ko update karenge naya node pe (top shift ho gaya)
        currSize++;                        // size badha do
    }

    // ---------------- Pop Operation ----------------
    int pop() {
        if (isEmpty()) {   // agar stack empty hai toh underflow
            cout << "Underflow\n";
            return INT_MIN;
        }
        Node* temp = head;             // temporary pointer top node ko store karega
        int poppedElement = temp->data; // top element ka data store karo
        head = head->next;             // head ko next node pe shift kar do (top remove ho gaya)
        delete temp;                   // purana top node delete kar do (memory free)
        currSize--;                    // size kam kar do
        return poppedElement;          // popped element return karo
    }

    // ---------------- Top Operation ----------------
    int top() {
        if (isEmpty()) {   // agar stack empty hai toh underflow
            cout << "Underflow\n";
            return INT_MIN;
        }
        return head->data; // head ka data hi top element hai
    }

    // ---------------- Size Operation ----------------
    int size() {
        return currSize;   // abhi kitne elements stack mein hai
    }

    // ---------------- Copy Stack Function ----------------
    Stack copyStack() {
        Stack temp(capacity);    // temporary stack (reverse order ke liye)
        Stack result(capacity);  // final copied stack

        // Step 1: input stack ke elements temp me daalo (reverse order)
        while (!isEmpty()) {
            int curr = pop();   // original se pop
            temp.push(curr);    // temp me push
        }

        // Step 2: temp se result me daalo (dobara reverse → original order)
        while (!temp.isEmpty()) {
            int curr = temp.pop();   // temp se pop
            result.push(curr);       // result me push
            push(curr);              // original stack ko restore bhi kar diya
        }

        return result;   // final copied stack return kar diya
    }
};

// ---------------- Main Function ----------------
int main() {
    Stack st(10);   // capacity 10 ka stack banaya

    // Push operations (elements stack me dalna)
    st.push(1);   // stack = [1]
    st.push(2);   // stack = [2, 1]
    st.push(3);   // stack = [3, 2, 1]
    st.push(4);   // stack = [4, 3, 2, 1] (top = 4)

    // copyStack function call kiya, "st" ko copy karke "res" me store kiya
    Stack res = st.copyStack();

    // Ab res stack ke elements print karenge
    while (!res.isEmpty()) {
        int curr = res.pop();   // res ka top element nikala
        cout << curr << endl;   // element print kiya
    }

    return 0;   // program successful end
}