#include<iostream>
#include<map>
using namespace std;
int longestSubstring(string s,int k){
     int n = s.size();
     int maxL = INT_MIN;
     map<char,int>mpp;
     for(int i=0;i<n;i++){
        mpp.clear();
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()<=k){
               maxL = max(maxL,(j-i+1));
            }
            else{
                break;
            }
        }
     }
     return maxL;

}
int main()
{
    string s="aaabbccd";
    cout<<longestSubstring(s,2);
 return 0;
}