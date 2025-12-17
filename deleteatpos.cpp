
//delete a node at an arbitary position 


#include <iostream>
using namespace std;

//  Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

//  Insert at tail (sirf list banane ke liye)
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {               // Agar list empty hai
        head = newNode;
        return;
    }

    Node* temp = head;                // temp ko head par rakha
    while (temp->next != NULL) {      // Jab tak last node na mil jaye
        temp = temp->next;            // temp ko next par move karte jao
    }

    temp->next = newNode;             // Last node ka next = new node
}

//  Delete node at ANY arbitrary position
void deleteAtPosition(Node*& head, int position) {

    //  Case 1: List empty
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    //  Case 2: Delete at head (position = 1)
    if (position == 1) {
        Node* temp = head;            // Purana head store kiya
        head = head->next;            // Head ko next node par shift kiya
        delete temp;                  // Purana head free
        return;
    }

    //  Case 3: Delete at any other position
    Node* temp = head;

    /*
         LOOP EXPLANATION (MOST IMPORTANT)
        Hume delete wale node ke *pehle* rukna hota hai.
        Isliye hum (position - 1)th node tak traverse karte hain.

        Example:
        Position = 3 delete karna hai
        Hume 2nd node par rukna hoga.

        Loop:
        i = 1 → temp = head
        i < position - 1 → i < 2 → true
        temp = temp->next → move to 2nd node
    */

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;            // temp ko aage move karte jao
    }

    //  Agar position list se bahar ho
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position\n";
        return;
    }

    /*
         DELETE LOGIC

        temp → node before the one to delete
        temp->next → node to delete
        temp->next->next → node after delete

        So we do:
        temp->next = temp->next->next;

        Yeh beech wale node ko list se unlink kar deta hai.
    */

    Node* nodeToDelete = temp->next;      // Delete hone wala node
    temp->next = temp->next->next;        // Link skip kiya (unlink)
    delete nodeToDelete;                  // Memory free
}

//  Display list
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

    //  Creating sample list: 10 -> 20 -> 30 -> 40 -> NULL
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List: ";
    display(head);

    // Delete node at position 3 (i.e., delete 30)
    deleteAtPosition(head, 3);

    cout << "After deleting position 3: ";
    display(head);

    return 0;
}