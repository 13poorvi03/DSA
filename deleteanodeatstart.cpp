/*
    ✅ LOGIC OF THE PROGRAM (Hinglish)

    Hum ek singly linked list bana rahe hain jisme:
    - Har node ke paas data aur next pointer hota hai.
    - deleteAtHead() function list ke head node ko delete karta hai.
        Steps:
        1. temp = head store karo
        2. head ko next node par shift karo
        3. purane head ko delete kar do
    - display() function list ko print karta hai.

    Main function me:
    - Pehle linked list banate hain
    - Fir deleteAtHead() call karke head node delete karte hain
*/

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

// ✅ Delete the head node of the linked list
void deleteAtHead(Node* &head) {
    if (head == NULL) {                 // Check if list is empty
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;                  // Store current head
    head = head->next;                  // Move head to next node
    delete temp;                        // Delete old head
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

    deleteAtHead(head);                 // Delete the head node

    display(head);                      // Print updated list

    return 0;
}