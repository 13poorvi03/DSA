#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;   // Jab node banta hai, uska next NULL hota hai
    }
};

// ---------------------------------------------
// INSERT AFTER A GIVEN NODE (Detailed Hinglish)
// ---------------------------------------------
void insertAfterNode(Node* givenNode, int data) {

    // Step 0: Check karo ki givenNode NULL to nahi
    // Agar NULL hua to hum uske baad insert nahi kar sakte
    if (givenNode == NULL) {
        cout << "Given node NULL hai, iske baad insert nahi ho sakta.\n";
        return;
    }

    // Step 1: Naya node banao
    // Yeh woh node hai jo hum list me insert karenge
    Node* newNode = new Node(data);

    // Step 2: Pehla pointer movement
    // newNode->next ko us node par point karwana hai
    // jisko givenNode->next point kar raha tha
    //
    // Basically:
    // newNode ko us jagah jod do jahan givenNode already jod raha tha
    //
    // Agar list: A -> B -> C
    // givenNode = B
    // to newNode->next = C
    newNode->next = givenNode->next;

    // Step 3: Doosra pointer movement
    // Ab givenNode->next ko newNode ki taraf mod do
    //
    // B -> newNode
    //
    // Iske baad list ban jayegi:
    // A -> B -> newNode -> C
    givenNode->next = newNode;
}

// ---------------------------------------------
// DISPLAY FUNCTION (Simple Traversal)
// ---------------------------------------------
void display(Node* head) {
    Node* temp = head;

    // Jab tak temp NULL nahi hota, list print karte jao
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;   // Next node par move karo
    }
    cout << "NULL\n";
}

// ---------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------
int main() {

    // Pehle ek simple linked list banate hain:
    // 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Original List:\n";
    display(head);

    // Hum 20 ke baad 50 insert karenge
    // givenNode = head->next (20)
    insertAfterNode(head->next, 50);

    cout << "After inserting 50 after 20:\n";
    display(head);

    return 0;
}