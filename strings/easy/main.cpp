#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s = "hithere";
    string w="";
    for(int i=0;i<s.length();i++){
        w+=s[i];

    }
    w+=" ";
    cout<<w;
}