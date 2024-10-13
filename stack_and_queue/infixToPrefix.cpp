#include<iostream>
#include<stack>
#include<algorithm> // For reverse function
using namespace std;

int prec(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void infixToPrefix(string s){
    stack<char> st;
    reverse(s.begin(), s.end());  // Reverse the infix expression
    string result;

    for(int i = 0; i < s.length(); i++){
        char c = s[i];

        // If the character is an operand, add it to result
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        }
        // If the character is ')', push it to the stack
        else if(c == ')'){
            st.push(c);
        }
        // If the character is '(', pop and output from the stack until ')' is found
        else if(c == '('){
            while(!st.empty() && st.top() != ')'){
                result += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // Pop the ')'
        }
        // Operator
        else {
            while(!st.empty() && prec(st.top()) > prec(c)){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the operators from the stack
    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());  // Reverse the result to get the prefix expression
    cout << result << endl;
}

int main() {
    string s = "x+y*z/w+u";
    infixToPrefix(s);
    return 0;
}
