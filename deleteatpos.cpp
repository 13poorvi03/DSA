
//delete a node at certain position 

#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert at tail (list banane ke liye)
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {      // last node tak jao
        temp = temp->next;
    }
    temp->next = newNode;
}

// ✅ Delete node at ANY arbitrary position (using WHILE LOOP)
void deleteAtPosition(Node*& head, int position) {

    // Case 1: Empty list
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Case 2: Delete head (position = 1)
    if (position == 1) {
        Node* temp = head;            // old head store
        head = head->next;            // head ko next par shift
        delete temp;                  // old head free
        return;
    }

    Node* temp = head;
    int count = 1;

    /*
        ✅ WHILE LOOP EXPLANATION

        Hume delete wale node ke *pehle* rukna hota hai.
        Isliye hum (position - 1)th node tak jaate hain.

        Example: delete position = 3
        Hume 2nd node par rukna hai.

        count = 1 → temp = head (1st node)
        count < position - 1 → 1 < 2 → true → temp = temp->next (2nd node)
        count = 2 → loop stops
    */

    while (temp != NULL && count < position - 1) {
        temp = temp->next;            // pointer aage move hota hai
        count++;
    }

    // Agar position list se bahar ho
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position\n";
        return;
    }

    /*
        ✅ DELETE LOGIC

        temp → node before the one to delete
        temp->next → node to delete
        temp->next->next → node after delete

        So:
        temp->next = temp->next->next;
    */

    Node* nodeToDelete = temp->next;      // delete hone wala node
    temp->next = temp->next->next;        // beech wala node skip
    delete nodeToDelete;                  // memory free
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

    // Creating sample list: 10 -> 20 -> 30 -> 40 -> NULL
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List: ";
    display(head);

    deleteAtPosition(head, 3);   // delete 30

    cout << "After deleting position 3: ";
    display(head);

    return 0;
}





//extraaaaaaaaaaaaaaaaaaaaaaaaaa---------------->

// void deleteatposition(Node* &head){
//     if(pos==0){
//         deleteathead(head);
//         return ;
//     }
//     int curr_pos=0;
//     Node* prev = head;
//     while(curr_pos!=pos-1){
//         prev= prev->next;
//         cur_poss++;
//     }
//     Node*temp = prev->next;
//     prev->next =prev->next->next;
//     delete(temp);
// }