//swap first node and second node

#include <iostream>
using namespace std;

class Node {
public:
    int data;      //  Node ka data store karega
    Node* next;    //  Next node ka address store karega (pointer)

    Node(int value) {
        data = value;   //  Constructor: data assign
        next = NULL;    //  Next ko NULL set (last node initially)
    }
};

//  Insert at tail (list ke end me node add karna)
void insertAtTail(Node*& head, int value) {

    //  Step 1: New node create
    Node* newNode = new Node(value);

    //  Case 1: Agar list empty hai
    if (head == NULL) {
        head = newNode;     // head ko newNode par point kara diya
        return;
    }

    //  Case 2: List empty nahi hai → last node tak jao
    Node* temp = head;

    //  Jab tak last node nahi milta (jiska next NULL ho)
    while (temp->next != NULL) {
        temp = temp->next;  // pointer ko aage badhao
    }

    //  Last node mil gaya → uske next me newNode attach
    temp->next = newNode;
}

//  Swap first two nodes of linked list
void swapFirstTwo(Node*& head) {

    //  Case: List empty ya sirf 1 node → swap possible nahi
    if (head == NULL || head->next == NULL) {
        cout << "Cannot swap, list too small\n";
        return;
    }

    /*
        POINTER WORKING (Step-by-Step)

        head → first node
        head->next → second node

        After swap:
        second → first
        first → third
    */

    Node* first = head;        //  Pehla node
    Node* second = head->next; //  Doosra node

    //  Step 1: first ka next ab third node ko point karega
    first->next = second->next;

    //  Step 2: second ka next ab first ko point karega
    second->next = first;

    //  Step 3: head ko second par shift kar do (new first node)
    head = second;
}

//  Display list
void display(Node* head) {
    Node* temp = head;

    // Jab tak list khatam na ho
    while (temp != NULL) {
        cout << temp->data << " -> ";  // data print
        temp = temp->next;             // pointer ko aage badhao
    }
    cout << "NULL\n";  //  End of list
}

int main() {

    //  Step 1: Create linked list
    Node* head = NULL;

    insertAtTail(head, 10);  // 10 add
    insertAtTail(head, 20);  // 20 add
    insertAtTail(head, 30);  // 30 add

    cout << "Original List: ";
    display(head);

    // Step 2: Swap first two nodes
    swapFirstTwo(head);

    cout << "After swapping first two nodes: ";
    display(head);

    return 0;
}