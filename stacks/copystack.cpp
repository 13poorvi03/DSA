//copy stack ----- copy contents of one stack to another in same order 

//whenever we transfer data from 1 stack to another it get reversed 

#include<iostream>   // iostream header file include kiya, input-output (cin, cout) ke liye
#include<stack>      // stack header file include kiya, STL stack use karne ke liye
using namespace std; // standard namespace use kar rahe hain, taaki "std::" baar-baar na likhna pade

// ---------------- Function to Copy a Stack ----------------
stack<int> copyStack(stack<int> input) {
    // yaha "stack<int>" matlab ek stack jo integers store karega
    // "input" parameter hai, jo original stack ko function me pass karenge

    stack<int> temp;   // ek temporary stack banaya, jo reverse order me elements store karega

    // Jab tak input stack empty nahi ho jata
    while (not input.empty()) {
        // "not input.empty()" matlab jab tak stack khaali nahi hai
        // input.empty() true hota hai agar stack empty hai, "not" uska ulta karega

        int curr = input.top();   // "top()" se current top element milta hai
        input.pop();              // "pop()" se top element remove kar diya
        temp.push(curr);          // us element ko temp stack me push kar diya
    }

    // Ab temp stack me elements reverse order me hain
    stack<int> result;   // ek naya stack banaya jo final copy store karega

    // Jab tak temp stack empty nahi ho jata
    while (not temp.empty()) {
        int curr = temp.top();   // temp ka top element nikala
        temp.pop();              // temp se remove kiya
        result.push(curr);       // result stack me push kiya
    }

    return result;   // final copied stack return kar diya
}

// ---------------- Main Function ----------------
int main() {
    stack<int> st;   // ek integer stack banaya jiska naam "st" hai

    // Push operations (elements stack me dalna)
    st.push(1);   // stack = [1]
    st.push(2);   // stack = [1, 2]
    st.push(3);   // stack = [1, 2, 3]
    st.push(4);   // stack = [1, 2, 3, 4] (top = 4)

    // copyStack function call kiya, "st" ko copy karke "res" me store kiya
    stack<int> res = copyStack(st);

    // Ab res stack ke elements print karenge
    while (not res.empty()) {
        int curr = res.top();   // res ka top element nikala
        res.pop();              // res se remove kiya
        cout << curr << endl;   // element print kiya
    }

    return 0;   // program successful end
}