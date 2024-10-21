#include<iostream>
#include<string>
#include<stack>
#include<algorithm>  // for reverse
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    int size = num.size();
    
    // Process each digit in the string
    for (int i = 0; i < size; i++) {
        // Remove top of stack if it's greater than current num[i] and k > 0
        while (!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        // Push current character into the stack
        st.push(num[i]);
    }
    
    // If there are remaining digits to remove, pop them from the stack
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    // Build the result from the stack (reverse order)
    string res = "";
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    
    // Reverse the result string to correct the order
    reverse(res.begin(), res.end());
    
    // Remove leading zeros from the result
    while (res.size() > 0 && res[0] == '0') {
        res.erase(res.begin());
    }
    
    // If the result is empty, return "0"
    if (res.empty()) {
        return "0";
    }
    
    return res;
}

int main() {
    string num = "1432219";
    cout << removeKdigits(num, 3) << endl;

    return 0;
}
