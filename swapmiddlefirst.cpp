#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert at tail
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Swap middle node and first node
void swapMiddleAndFirst(Node*& head) {

    // List empty or only 1 node
    if (head == NULL || head->next == NULL) {
        cout << "Cannot swap, list too small\n";
        return;
    }

    // Step 1: Find middle node (slow-fast method)
    Node* slow = head;
    Node* fast = head;
    Node* prevMid = NULL;

    while (fast != NULL && fast->next != NULL) {
        prevMid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow = middle node
    // prevMid = node before middle

    // If middle is already head (only 2 nodes case)
    if (slow == head) {
        cout << "Middle is same as first, no swap needed\n";
        return;
    }

    // Step 2: Swap middle and head

    // prevMid ka next ab head ko point karega
    prevMid->next = head;

    // Swap next pointers
    Node* temp = slow->next;
    slow->next = head->next;
    head->next = temp;

    // Step 3: Update head to middle
    head = slow;
}

// Display list
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

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    cout << "Original List: ";
    display(head);

    swapMiddleAndFirst(head);

    cout << "After swapping middle and first node: ";
    display(head);

    return 0;
}