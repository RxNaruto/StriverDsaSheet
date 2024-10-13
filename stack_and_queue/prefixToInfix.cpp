#include<iostream>
#include<stack>
using namespace std;
string prefixToInfix(string s){
    stack<string>st;
    for(int i=s.length()-1;i>=0;i--){
        char c=s[i];
        
      

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
           st.push(string(1,c));
        }
        else{
            string a=st.top();
            st.pop();
            string b= st.top();
            st.pop();
            string con = '(' + a+ s[i] + b+')';
            st.push(con);

        }
    }
    return st.top();
}

int main()
{
    string s = "*-A/BC-/AKL";
    cout<<"PrefixToInfix: "<<prefixToInfix(s);
 return 0;
}