#include <iostream>
using namespace std;

/*
  Stack ko linked list se implement kar rahe hain.
  Har element ek Node hoga jisme data aur next pointer hoga.
*/

class Node {
public:
    int data;      // current node ka integer data
    Node* next;    // next node ka pointer (linked list chain)

    // Constructor: naya Node banate hi data set aur next ko NULL kar dete hain
    Node(int value) {
        // Step 1: value ko node ke data mein copy karo
        data = value;
        // Step 2: abhi ye node kisi ko point nahi karta, isliye next = NULL
        next = NULL;
    }
};

class Stack {
    // Private members: internal state of the stack
    Node* top;   // stack ka top pointer: last pushed node ko point karta hai
    int size;    // kitne elements currently stack mein hain

public:
    // Constructor: empty stack initialize
    Stack() {
        // Step 1: jab stack create hota hai, top = NULL (empty state)
        top = NULL;
        // Step 2: empty stack ka size 0 hota hai
        size = 0;
    }

    // Push operation: value ko stack ke top par add karta hai
    void push(int value) {
        // Step 1: naya Node allocate karo heap par jisme data = value hoga
        Node* temp = new Node(value);

        // Step 2: memory allocation failure check (rare in C++, par safety)
        if (temp == NULL) {
            // Agar memory nahi mili toh push impossible -> overflow
            cout << "Stack overflow\n";
            return; // operation yahin stop
        }

        // Step 3: naya node ka next purane top ko point karega
        // Reason: Linked list ka head change karna hai, chain continue rahe
        temp->next = top;

        // Step 4: top ko update karo: ab top naya node hai
        top = temp;

        // Step 5: size badhao, kyunki ek element add hua
        size++;

        // Step 6: user feedback (console output)
        cout << "Pushed " << value << " into the stack\n";
    }

    // Pop operation: top element ko remove karta hai
    void pop() {
        // Step 1: empty check -> agar top NULL hai, pop possible nahi
        if (top == NULL) {
            cout << "Stack underflow\n";
            return; // operation stop
        }

        // Step 2: current top ko temporarily store karo delete karne ke liye
        Node* temp = top;

        // Step 3: user feedback: kaunsa element pop ho raha hai
        cout << "Popped " << top->data << " from the stack\n";

        // Step 4: top ko next node par shift karo (chain ka second node)
        // Isse linked list ka head aage move ho jata hai
        top = top->next;

        // Step 5: old top node ko free/delete karo (memory leak na ho)
        delete temp;

        // Step 6: size kam karo, kyunki ek element remove hua
        size--;
    }

    // Peek operation: top element ka data return karta hai bina remove kiye
    int peek() {
        // Step 1: empty check -> agar empty hai, meaningful value nahi
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1; // sentinel value (exam-safe)
        }
        // Step 2: top ke data ko return karo
        return top->data;
    }

    // IsEmpty: true/false batata hai ki stack empty hai ya nahi
    bool IsEmpty() {
        // Step: agar top NULL hai -> empty, warna not empty
        return top == NULL;
    }

    // IsSize: current element count return karta hai
    int IsSize() {
        // Step: maintained size directly return
        return size;
    }
};

int main() {
    // Step 1: ek stack object banao (initially empty)
    Stack s;

    // Step 2: push operations (top par add hote jayenge - LIFO)
    // After push(10): top=10, size=1
    s.push(10);
    // After push(23): top=23 -> 10, size=2
    s.push(23);
    // After push(25): top=25 -> 23 -> 10, size=3
    s.push(25);
    // After push(76): top=76 -> 25 -> 23 -> 10, size=4
    s.push(76);
    // After push(28): top=28 -> 76 -> 25 -> 23 -> 10, size=5
    s.push(28);

    // Step 3: pop (top element 28 remove hoga)
    // After pop(): top=76 -> 25 -> 23 -> 10, size=4
    s.pop();

    // Step 4: empty check (0 means false -> not empty)
    cout << "IsEmpty: " << s.IsEmpty() << endl;

    // Step 5: current size print (expected 4)
    cout << "Size: " << s.IsSize() << endl;

    // Step 6: peek demonstration (optional): top ka data dekhna ho toh
    // cout << "Peek: " << s.peek() << endl; // expected 76

    return 0; // program successful end
}