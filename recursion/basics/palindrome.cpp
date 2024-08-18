#include<iostream>
using namespace std;
bool palindrome(string& s, int i){
    if(i>=s.length()/2){
        return true;
    }
    if(s[i]!=s[s.length()-1-i]){
        return false;
    }
    return palindrome(s,i+1);
}
int main()
{
    string s = "ABCDCBA";
    cout<<"is ABCDCBA plaindrome"<<palindrome(s,0);
 return 0;
}