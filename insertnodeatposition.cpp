#include <iostream>
using namespace std;

class Node {
public:
    int data;      // ✅ Node ka actual value store hota hai
    Node* next;    // ✅ Next pointer next node ka address store karta hai
};

Node* head = NULL;   // ✅ Initially list empty hai, isliye head = NULL

// ✅ INSERT AT MIDDLE (Insert at a given position)
void insertAtPosition(int value, int position) {

    // ---------------------------------------------------------
    // ✅ STEP 1: Create a new node
    // ---------------------------------------------------------
    Node* newNode = new Node();   // memory allocate ki
    newNode->data = value;        // new node me value store ki
    newNode->next = NULL;         // next pointer ko NULL rakha (baad me set hoga)

    // ---------------------------------------------------------
    // ✅ STEP 2: Special Case — Insert at position 1
    // ---------------------------------------------------------
    // Agar position 1 hai, to new node ko head banana padega
    if (position == 1) {
        newNode->next = head;   // new node ka next purane head ko point karega
        head = newNode;         // head ko new node bana diya
        return;                 // insertion complete
    }
   
    // ---------------------------------------------------------
    // ✅ STEP 3: Traverse to (position - 1)
    // ---------------------------------------------------------
    // Hume us node tak jana hai jiske baad new node insert hoga
    Node* temp = head;          // traversal head se start hota hai
    int count = 1;              // current node ka position track karne ke liye

    // Jab tak hum (position - 1) wale node tak nahi pahunchte, aage badhte raho
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;      // pointer ko next node par move karo
        count++;                // position count badhao
    }

    // ---------------------------------------------------------
    // ✅ STEP 4: Invalid Position Check
    // ---------------------------------------------------------
    // Agar temp NULL ho gaya, matlab list me utne nodes hi nahi hain
    if (temp == NULL) {
        cout << "Invalid position";
        return;
    }
 
    // ---------------------------------------------------------
    // ✅ STEP 5: Insert the new node in the middle
    // ---------------------------------------------------------
    // Linking ka sequence bohot important hota hai:

    // 1) newNode ka next us node ko point karega jo abhi temp ke baad hai
    newNode->next = temp->next;

    // 2) temp ka next ab newNode ko point karega
    temp->next = newNode;

    // ✅ Ab newNode beech me successfully insert ho chuka hai
}

// ✅ DISPLAY FUNCTION
void display() {

    // ---------------------------------------------------------
    // ✅ STEP 1: Check if list is empty
    // ---------------------------------------------------------
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    // ---------------------------------------------------------
    // ✅ STEP 2: Traverse and print all nodes
    // ---------------------------------------------------------
    Node* temp = head;          // traversal head se start hota hai
    while (temp != NULL) {
        cout << temp->data << " ";   // current node ka data print karo
        temp = temp->next;           // next node par move karo
    }
}

int main() {

    // ---------------------------------------------------------
    // ✅ Testing insert-at-middle
    // ---------------------------------------------------------

    insertAtPosition(10, 1);  // List: 10
     display();
    // Explanation: 10 ko position 1 par insert kiya → head = 10
    cout<<endl;
    insertAtPosition(30, 2);  // List: 10 → 30
     display();
     cout<<endl;
    // Explanation: 30 ko position 2 par insert kiya → 10 ke baad 30

    insertAtPosition(20, 2);  // List: 10 → 20 → 30
    // Explanation: 20 ko position 2 par insert kiya → 10 ke baad 20, phir 30

    display();  // Output: 10 20 30

    return 0;
}