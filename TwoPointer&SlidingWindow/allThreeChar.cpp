#include<iostream>
#include<vector>
using namespace std;
int allThree(string s){
    int cnt=0;
    int n = s.size();
    for(int i=0;i<n;i++){
        vector<int>hash(3,0);

        for(int j=0;j<n;j++){
            hash[s[j]-'a'] = 1;
            if((hash[0]+hash[1]+hash[2])==3){
                cnt = cnt+(n-j);
                break;
            }
        }
    }
    return cnt;
}
int main()
{
    string s="abcabc";
    cout<<allThree(s);
 return 0;
}