#include <iostream>
#include <climits>   // INT_MIN ke liye
using namespace std;

// Stack class banayi hai
class Stack {
    int capacity;   // stack ki maximum size
    int* arr;       // dynamic array jo stack ke elements store karega
    int topIndex;   // stack ke top element ka index (initially -1)

public:
    // Constructor: jab object banega tab capacity set hogi aur array allocate hoga
    Stack(int c) {
        this->capacity = c;       // "this" current object ko refer karta hai
        arr = new int[c];         // dynamic memory allocate kar rahe hai array ke liye
        this->topIndex = -1;      // initially stack empty hai
    }

    // Push function: naya element stack ke top pe daalna
    void push(int data) {
        if (this->topIndex == this->capacity - 1) { // agar stack full hai
            cout << "overflow\n";   // overflow message
            return;
        }
        this->topIndex++;           // topIndex ko ek step aage badhao
        this->arr[this->topIndex] = data; // naya element top pe daal do
    }

    // Pop function: top element ko remove karna
    int pop() {
        if (this->topIndex == -1) {   // agar stack empty hai
            cout << "underflow\n";    // underflow message
            return INT_MIN;           // error ke liye INT_MIN return kar rahe
        }
        int poppedElement = this->arr[this->topIndex]; // top element store karo
        this->topIndex--;             // topIndex ko ek step peeche le jao
        return poppedElement;         // popped element return karo
    }

    // Top function: current top element ko dekhna (remove nahi karna)
    int top() {
        if (this->topIndex == -1) {   // agar stack empty hai
            cout << "underflow\n";
            return INT_MIN;           // error ke liye INT_MIN
        }
        return this->arr[this->topIndex]; // top element return karo
    }

    // Stack empty hai ya nahi check karna
    bool isempty() {
        return this->topIndex == -1;
    }

    // Stack ka current size (kitne elements hai)
    int size() {
        return this->topIndex + 1;
    }

    // Stack full hai ya nahi check karna
    bool isfull() {
        return this->topIndex == this->capacity - 1;
    }
};

int main() {
    Stack st(5);        // ek stack banaya jiska capacity 5 hai
    st.push(1);         // element 1 push kiya
    st.push(2);         // element 2 push kiya
    st.push(3);         // element 3 push kiya

    cout << st.top() << "\n";   // abhi top element print hoga (3)

    cout << st.pop() << "\n";   // top element (3) pop hoga
    cout << st.top() << "\n";   // ab top element (2) print hoga

    return 0;
}