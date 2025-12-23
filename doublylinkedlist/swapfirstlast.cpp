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

// Swap first and last node
void swapFirstLast(Node*& head) {
    if (head == NULL || head->next == NULL) {
        cout << "Swap not possible (list too short)" << endl;
        return;
    }

    Node* first = head;
    Node* last = head;

    // Traverse to last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Case: only 2 nodes
    if (first->next == last) {
        last->next = first;
        last->prev = NULL;
        first->prev = last;
        first->next = NULL;
        head = last;
        return;
    }

    // General case: more than 2 nodes
    Node* second = first->next;
    Node* beforeLast = last->prev;

    // Adjust neighbors
    second->prev = last;
    beforeLast->next = first;

    // Swap first and last links
    last->next = second;
    last->prev = NULL;

    first->next = NULL;
    first->prev = beforeLast;

    // Update head
    head = last;
}

int main() {
    Node* head = NULL;

    // Initial list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Before Swap: ";
    printList(head);

    // Swap first and last
    swapFirstLast(head);

    cout << "After Swap:  ";
    printList(head);

    return 0;
}