#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to add a node at the start
void insertAtStart(Node*& head, int value) {
    // Step 1: Create new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;   // First node has no previous
    newNode->next = head;   // Link new node to current head

    // Step 2: If list is not empty, update old head's prev
    if (head != NULL) {
        head->prev = newNode;
    }

    // Step 3: Move head to new node
    head = newNode;
}

// Function to print list forward
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL; // Empty list

    // Insert nodes at start
    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);

    // Print list
    cout << "Doubly Linked List: ";
    printList(head);

    return 0;
}