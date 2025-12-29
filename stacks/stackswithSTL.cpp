#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>S;
    S.push(10);
    S.push(12);
    S.push(13);
    S.push(14);
    // cout<<"the size of stacks is : "<<S.size()<<endl;
    // cout<<"the top element of the stack is : "<<S.top()<<endl;
    S.pop();
    cout<<"the size of stacks is : "<<S.size()<<endl;
    cout<<"the top element of the stack is : "<<S.top()<<endl;
    cout<<S.empty()<<endl;
    return 0;
}