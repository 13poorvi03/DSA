#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);   // initially sab -1
    stack<int> st;               // stack mein indices store karenge

    for (int i = 0; i < n; i++) {
        // jab tak stack empty nahi hai aur current element bada hai
        // stack ke top index ke element se
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i];  // next greater mil gaya
            st.pop();                   // us index ko remove kar do
        }
        st.push(i);  // current index ko stack mein daal do
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}