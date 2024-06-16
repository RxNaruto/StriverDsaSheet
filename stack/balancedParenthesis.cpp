#include<iostream>
#include<stack>
using namespace std;
bool balancedParenthesis(string s){
    int l= s.length();
    stack<int>st;
    for(int i=0;i<l;i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]=='}'){
            if(st.top()!='{'){
                 return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]==')'){
            if(st.top()!='('){
                 return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]==']'){
            if(st.top()!='['){
                 return false;
            }
            else{
                st.pop();
            }
        }

    }
    return true;
}
int main()
{
    string s="{[(]}";
    cout<<"Balanced Paranthesis "<<balancedParenthesis(s);
 return 0;
}