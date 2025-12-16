//delete a node at end

#include <iostream>
using namespace std;

class Node {
public:
    int data;        // Stores node data
    Node* next;      // Pointer to the next node

    Node(int val) {  // Constructor to initialize node
        data = val;
        next = NULL;
    }
};

// ✅ Delete the last node of the linked list
void deletenodeatend(Node* &head){

    // ✅ Case 1: List is empty
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // ✅ Case 2: Only one node in the list
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* second_last = head;

    // ✅ jab tak second_last->next->next null nhi ho jata
    // (means yeh loop tab tak chalega jb tak second last node jo h
    // uske jo next hoga wo last node hoga jiska next null hota h
    // so jb tak last node na mil jaye tb tk yeh chalega)
    while (second_last->next->next != NULL) {
        second_last = second_last->next;    // second_last pointer keep moving to next node
    }

    // ✅ now second_last points to second last node
    Node* temp = second_last->next;    // last node will be temp which we have to delete

    second_last->next = NULL;          // second_last ke next mae hum null daaldenge wo humara last node bn jayega

    delete temp;                       // delete last node (free nhi, delete use karna h)
}

// ✅ Display the linked list
void display(Node* head) {
    Node* temp = head;                  // Pointer for traversal

    while (temp != NULL) {
        cout << temp->data << " -> ";   // Print node data
        temp = temp->next;              // Move to next node
    }
    cout << "NULL" << endl;             // End of list
}

int main() {

    // ✅ Creating a sample linked list: 10 -> 20 -> 30 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    display(head);                      // Print original list

    deletenodeatend(head);              // Delete the last node

    display(head);                      // Print updated list

    return 0;
}