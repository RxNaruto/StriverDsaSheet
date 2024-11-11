#include<iostream>
#include<vector>
using namespace std;
int longestSubstring(string s){
    int l=0,r=0,len=0;
    int maxL = INT_MIN;
    vector<int>hash(256,-1);
    while(r<s.size()){
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }

        }
        len = r-l+1;
        maxL = max(maxL,len);
        hash[s[r]]=r;
        r++;
    }
    return maxL;
}
int main()
{
    string s = "cadbzabcd";
    cout<<longestSubstring(s);
 return 0;
}