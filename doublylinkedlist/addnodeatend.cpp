#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to print list forward with arrows
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " -> ";  // arrow between nodes
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert at end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node* head = NULL;

    // Initial list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);

    cout << "Before Insertion: ";
    printList(head);

    // Insert new node at end
    insertAtEnd(head, 30);

    cout << "After Insertion:  ";
    printList(head);

    return 0;
}