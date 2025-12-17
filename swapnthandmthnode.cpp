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

// Swap nth and mth node
void swapNthAndMth(Node*& head, int n, int m) {

    // If both positions same → no need to swap
    if (n == m) return;

    Node *prevN = NULL, *currN = head;
    Node *prevM = NULL, *currM = head;

    int pos = 1;

    // Find nth node
    while (currN != NULL && pos < n) {
        prevN = currN;
        currN = currN->next;
        pos++;
    }

    pos = 1;

    // Find mth node
    while (currM != NULL && pos < m) {
        prevM = currM;
        currM = currM->next;
        pos++;
    }

    // If either node doesn't exist
    if (currN == NULL || currM == NULL) {
        cout << "Invalid positions\n";
        return;
    }

    // If nth node is not head
    if (prevN != NULL)
        prevN->next = currM;
    else
        head = currM;

    // If mth node is not head
    if (prevM != NULL)
        prevM->next = currN;
    else
        head = currN;

    // Swap next pointers
    Node* temp = currN->next;
    currN->next = currM->next;
    currM->next = temp;
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

    // Swap nth and mth node
    swapNthAndMth(head, 2, 5);

    cout << "After swapping 2nd and 5th node: ";
    display(head);

    return 0;
}