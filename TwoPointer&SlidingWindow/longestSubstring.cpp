#include<iostream>
#include<vector>
using namespace std;
int longestSubstring(string s){
    int length,maxLen;
    for(int i=0;i<s.length();i++){
        vector<int>hash(256,0);
        for(int j=0;j<s.length();j++){
            if(hash[s[j]]==1)break;
            length = j-i+1;
            maxLen = max(length,maxLen);
            hash[s[j]]=1;
        }
    }
    return maxLen;
}
int main()
{
    string s="bbbbb";
    cout<<longestSubstring(s);
 return 0;
}