#include<iostream>
#include<vector>
using namespace std;
int repeatingCharacters(string s,int k){
    int n = s.size();
    int maxF = INT_MIN;
    int changes = INT_MIN;
    int maxLen = INT_MIN;
    for(int i=0;i<n;i++){
        vector<int>hash(26,0);
        for(int j=0;j<n;j++){
            hash[s[j]]++;
            maxF = max(maxF,hash[s[j]]);
            changes = (j-i+1)-maxF;
            if(changes<=k){
                maxLen = max(maxLen,(j-i+1));
            }
            else{
                break;
            }

        }

    }
    return maxLen;
}
int main()
{
    string s="ABAB";
    cout<<repeatingCharacters(s,2);
 return 0;
}