#include<iostream>
#include<string>
#include<stack>
using namespace std;
void reverseString(string s){
    stack<string>st;
    string ans="";
     string word="";
    for(int i=0;i<=s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                 word+=s[i];
            }
            else{
                st.push(word);
                st.push(" ");
                word="";
            }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
      
        
     
    }
 

}
int main()
{
    string s ="the sky is blue";
    reverseString(s);
 return 0;
}