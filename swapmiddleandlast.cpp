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

// Swap middle node and last node
void swapMiddleAndLast(Node*& head) {

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

    // Now: slow = middle node
    // prevMid = node before middle

    // Step 2: Find last and second last node
    Node* last = head;
    Node* prevLast = NULL;

    while (last->next != NULL) {
        prevLast = last;
        last = last->next;
    }

    // Case: If middle and last are same (only 2 nodes)
    if (slow == last) {
        cout << "Middle and last are same, no swap needed\n";
        return;
    }

    // Step 3: Adjust previous pointers
    if (prevMid != NULL)
        prevMid->next = last;
    else
        head = last;  // If middle was head

    prevLast->next = slow;

    // Step 4: Swap next pointers
    Node* temp = slow->next;
    slow->next = last->next;
    last->next = temp;

    // Step 5: If middle was head, update head
    if (head == slow)
        head = last;
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

    swapMiddleAndLast(head);

    cout << "After swapping middle and last node: ";
    display(head);

    return 0;
}