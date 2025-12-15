//update the linked list 

#include <iostream>
using namespace std;

class Node {
public:
    int data;        // Node ka data
    Node* next;      // Next pointer

    Node(int val) {  // Constructor
        data = val;
        next = NULL;
    }
};

Node* head = NULL;   // Initially list empty

// Insert at end (taaki list bana sako)
void insertAtEnd(int val) {
    Node* newNode = new Node(val);

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

// Update value at given position
void updateAtPos(Node* &head, int pos, int val) {
    Node* temp = head;
    int curr_pos = 0;

    while (temp != NULL && curr_pos != pos) {
        temp = temp->next;
        curr_pos++;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    temp->data = val;   // Update value
}

// Display linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    cout << "Before update: ";
    display(head);

    updateAtPos(head, 2, 99);   // pos = 2 means 3rd node

    cout << "After update: ";
    display(head);

    return 0;
}