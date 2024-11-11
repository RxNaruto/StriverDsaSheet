#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int threeChar(string s){
    vector<int>lastSeen(3,-1);
    int n = s.length();
    int cnt=0;
    for(int i=0;i<n;i++){
        lastSeen[s[i]-'a']=i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            cnt = cnt+(1+min({lastSeen[0],lastSeen[1],lastSeen[2]}));
        }
    }
    return cnt;
}

int main()
{
    string s="abcabc";
    cout<<threeChar(s);
 return 0;
}