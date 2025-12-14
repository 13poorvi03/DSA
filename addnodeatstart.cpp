#include<iostream>
using namespace std;

// Node class: ek node me 2 cheeze hoti hain:
// 1) val  -> data store karta hai
// 2) next -> next node ka address store karta hai
class Node{
public:
    int val;
    Node* next;

    // Constructor: jab bhi new Node banega, ye run hoga
    Node(int data){
        val = data;      // node ke andar value daal di
        next = NULL;     // next pointer ko NULL set kiya (abhi koi next node nahi)
    }
};

// Linked List ke START me node insert karna
// head ko reference (&) se pass kiya hai taaki actual head change ho sake
void insertAtstart(Node* &head, int val){

    // Step 1: naya node banao
    Node* new_node = new Node(val);
    // new_node ek pointer hai jo naye node ka address store karta hai

    // Step 2: naye node ka next = current head
    // Yani jo pehle first node tha, uska address ab new_node->next me jayega
    new_node->next = head;

    // Step 3: head ko update karo
    // Ab head ko bol do ki tu new_node ko point kare
    head = new_node;
}

// Linked List ko print karna
// head ko sirf read karna hai, change nahi karna, isliye & nahi lagaya
void display(Node* head){

    // temp ek pointer hai jo list ko traverse karega
    Node* temp = head;

    // Jab tak temp NULL nahi hota, tab tak nodes print karte jao
    while(temp != NULL){

        // temp jis node ko point kar raha hai, uska value print karo
        cout << temp->val << "->";

        // temp ko next node par move karo
        // Yani temp me next node ka address aa jayega
        temp = temp->next;
    }

    // Jab temp NULL ho jaye, matlab list end ho gayi
    cout << "NULL" << endl;
}

int main(){

    // Starting me list empty hai, isliye head = NULL
    Node* head = NULL;

    // Insert 2 at start
    // head NULL tha, ab head 2 wale node ko point karega
    insertAtstart(head, 2);
    display(head);

    // Insert 1 at start
    // 1 ka next = 2 ka address
    // head = 1
    insertAtstart(head, 1);
    display(head);

    // Insert 0 at start
    // 0 ka next = 1 ka address
    // head = 0
    insertAtstart(head, 0);
    display(head);

    return 0;
}