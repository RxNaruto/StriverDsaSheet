#include<iostream>
#include<map>
using namespace std;
int longestSub(string s,int k){
    int size = s.size();
    int l=0,r=0,maxL=0;
    map<char,int>mpp;
    while(r<size){
        mpp[s[r]]++;
        while(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
            

        }
        if(mpp.size()<=k){
            maxL = max(maxL,(r-l+1));
        }
        r++;
    }
    return maxL;
}
int main()
{
    string s = "aaabbccd";
    cout<<longestSub(s,2);
 return 0;
}