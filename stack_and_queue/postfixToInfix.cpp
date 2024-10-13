#include<iostream>
#include<stack>
using namespace std;
string postfixToinfix(string s){
    int i=0;
    stack<string>st;
    while(i<s.length()){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            st.push(string(1,c));
        }
        else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string con = '('+b+s[i]+a+')';
            st.push(con);
        }
        i++;
    }
    return st.top();
}
int main()
{
    string s = "ab*c+";
    cout<<postfixToinfix(s);
 return 0;
}