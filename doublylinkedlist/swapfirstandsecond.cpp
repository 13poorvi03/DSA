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

// Swap first and second node
void swapFirstSecond(Node*& head) {
    if (head == NULL || head->next == NULL) {
        cout << "Swap not possible (list too short)" << endl;
        return;
    }

    Node* first = head;
    Node* second = head->next;

    // Adjust links
    first->next = second->next;
    if (second->next != NULL) {
        second->next->prev = first;
    }

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    // Update head
    head = second;
}

int main() {
    Node* head = NULL;

    // Initial list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Before Swap: ";
    printList(head);

    // Swap first and second
    swapFirstSecond(head);

    cout << "After Swap:  ";
    printList(head);

    return 0;
}