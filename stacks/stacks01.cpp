#include<iostream>
#include<stack>
using namespace std;
int main(){
  stack<int>st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  cout<<"top element of the stack : "<<st.top()<<endl;
  st.pop();
  cout<<"after pop : "<<st.top()<<endl;
  st.push(7);
  cout<<"after push : "<<st.top()<<endl;
  cout<<st.empty()<<endl;
    return 0;
}