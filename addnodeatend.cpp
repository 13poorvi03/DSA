#include<iostream>
using namespace std;

// Node class: Linked List ka basic building block
// Har node me 2 cheeze hoti hain:
// 1) val  -> data store karta hai
// 2) next -> next node ka address store karta hai
class Node{
public:
    int val;
    Node* next;

    // Constructor: jab bhi new Node banega, ye run hoga
    Node(int data){
        val = data;      // node ke andar value store kar di
        next = NULL;     // next pointer ko NULL set kiya (abhi koi next node nahi)
    }
};

// ------------------------------------------------------------
// INSERT AT END FUNCTION
// ------------------------------------------------------------
// Linked List ke END me naya node add karna
// head ko reference (&) se pass kiya hai taaki actual head modify ho sake
void insertAtEnd(Node* &head, int val){

    // Step 1: Naya node banao jisme 'val' store ho
    // new_node ek pointer hai jo naye node ka address store karega
    Node* new_node = new Node(val);

    // Step 2: Agar list empty hai (head == NULL)
    // To naya node hi first node ban jayega
    if(head == NULL){
        head = new_node;   // head ab new_node ko point karega
        return;            // function yahin khatam
    }

    // Step 3: Agar list empty nahi hai
    // To hume last node tak travel karna padega
    // Iske liye temp pointer banate hain jo head se start karega
    Node* temp = head;

    // Step 4: temp ko last node tak le jao
    // Jab tak temp->next NULL nahi hota, tab tak aage badhte jao
    // temp->next == NULL ka matlab: temp last node par hai
    while(temp->next != NULL){
        temp = temp->next;   // temp ko next node par move karo
    }

    // Step 5: Ab temp last node par hai
    // Last node ka next pointer NULL hota hai
    // Ab hum uske next me new_node ka address daal denge
    temp->next = new_node;   // new_node list ke end me attach ho gaya
}

// ------------------------------------------------------------
// DISPLAY FUNCTION
// ------------------------------------------------------------
// Linked List ke saare nodes print karna
void display(Node* head){

    // temp pointer list ko traverse karega
    Node* temp = head;

    // Jab tak temp NULL nahi hota, tab tak nodes print karte jao
    while(temp != NULL){

        // temp jis node ko point kar raha hai, uska value print karo
        cout << temp->val << "->";

        // temp ko next node par move karo
        temp = temp->next;
    }

    // Jab temp NULL ho jaye, matlab list end ho gayi
    cout << "NULL" << endl;
}

// ------------------------------------------------------------
// MAIN FUNCTION
// ------------------------------------------------------------
int main(){

    // Starting me list empty hai, isliye head = NULL
    Node* head = NULL;

    // Insert at end
    insertAtEnd(head, 10);   // list: 10->NULL
     display(head);

    insertAtEnd(head, 20);   // list: 10->20->NULL
     display(head);

    insertAtEnd(head, 30);   // list: 10->20->30->NULL
     display(head);

    insertAtEnd(head, 40);   // list: 10->20->30->40->NULL

    // Display the list
    display(head);

    return 0;
}