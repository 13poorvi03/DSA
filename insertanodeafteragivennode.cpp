//insert a node after a given node 

#include <iostream>
using namespace std;

class Node {
public:
    int data;      // Node ka data
    Node* next;    // Next pointer
};

Node* head = NULL;   // Initially list empty

// ✅ INSERT A NODE AFTER A GIVEN NODE
void insertAfter(Node* prevNode, int value) {

    // ---------------------------------------------------------
    // ✅ STEP 1: Check if given node is NULL
    // ---------------------------------------------------------
    if (prevNode == NULL) {
        cout << "Given node cannot be NULL";
        return;
    }

    // ---------------------------------------------------------
    // ✅ STEP 2: Create a new node
    // ---------------------------------------------------------
    Node* newNode = new Node();
    newNode->data = value;

    // ---------------------------------------------------------
    // ✅ STEP 3: Linking (order is VERY important)
    // ---------------------------------------------------------
    newNode->next = prevNode->next;   // new node → next node
    prevNode->next = newNode;         // prev node → new node

    // ✅ Node successfully inserted after prevNode
}

// ✅ DISPLAY FUNCTION
void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "List is empty";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    // ✅ Creating a small list manually
    head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};

    cout << "Before insertion: ";
    display();

    // ✅ Insert 25 after node with data 20
    insertAfter(head->next, 25);

    cout << "After insertion: ";
    display();

    return 0;
}