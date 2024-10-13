#include<iostream>
#include<stack>
using namespace std;
string postfixToPrefix(string s){
    stack<string>st;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
           st.push(string(1,c));
        }
        else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string con = s[i]+b+a;
            st.push(con);
        }



    }
    return st.top();
}
int main()
{
    string s = "ABC/-AK/L-*";
    cout<<postfixToPrefix(s);
 return 0;
}