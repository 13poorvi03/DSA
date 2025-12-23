#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Print list with arrows
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at end (helper)
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
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at any position
void insertAtPosition(Node*& head, int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;

    // Case 1: Insert at start
    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to node before position
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // If position is beyond length, insert at end
    if (temp == NULL || temp->next == NULL) {
        newNode->next = NULL;
        newNode->prev = temp;
        if (temp != NULL) temp->next = newNode;
        return;
    }

    // Insert in middle
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    // Initial list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 40);

    cout << "Before Insertion: ";
    printList(head);

    // Insert 30 at position 3 (between 20 and 40)
    insertAtPosition(head, 30, 3);

    cout << "After Insertion:  ";
    printList(head);

    return 0;
}