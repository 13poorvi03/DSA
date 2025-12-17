#include <iostream>
using namespace std;

class Node {
public:
    int data;        // Node ka data
    Node* next;      // Next node ka pointer

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert at tail (list ke end me node add karna)
void insertAtTail(Node*& head, int value) {

    Node* newNode = new Node(value);  // New node create

    // Agar list empty hai
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Last node tak traversal
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Last node ke next me new node attach
    temp->next = newNode;
}

// Swap first and last node of linked list
void swapFirstAndLast(Node*& head) {

    // List empty ya sirf 1 node → swap possible nahi
    if (head == NULL || head->next == NULL) {
        cout << "Cannot swap, list too small\n";
        return;
    }

    // Case: Only 2 nodes → simple swap
    if (head->next->next == NULL) {
        Node* first = head;
        Node* second = head->next;

        second->next = first;   // second → first
        first->next = NULL;     // first → NULL
        head = second;          // head update

        return;
    }

    // Case: More than 2 nodes
    Node* first = head;        // Pehla node
    Node* prevLast = NULL;     // Last ke pehle wala node
    Node* last = head;         // Last node find karenge

    // Last aur prevLast find karna
    while (last->next != NULL) {
        prevLast = last;       // Second last store
        last = last->next;     // Aage badhte jao
    }

    // prevLast → second last node
    // last → last node

    // Step 1: prevLast ka next ab first ko point karega
    prevLast->next = first;

    // Step 2: last ka next ab first->next ko point karega
    last->next = first->next;

    // Step 3: first ka next NULL hoga (kyunki ab last ban gaya)
    first->next = NULL;

    // Step 4: head ko last par shift kar do
    head = last;
}

// Display linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {

    Node* head = NULL;

    // List create karna
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List: ";
    display(head);

    // Swap first and last node
    swapFirstAndLast(head);

    cout << "After swapping first and last node: ";
    display(head);

    return 0;
}