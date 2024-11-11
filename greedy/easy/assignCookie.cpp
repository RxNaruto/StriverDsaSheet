#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int cookieAssign(vector<int>greed,vector<int>cookie){
    int n = greed.size();
    int m = cookie.size();
    int l=0,r=0,cnt=0;
    sort(greed.begin(),greed.end());
    sort(cookie.begin(),cookie.end());
    while(l<m && r<n){
        if(cookie[l]>=greed[r]){
            cnt = cnt+1;
            
            r++;
        }
        l++;
    }
    return cnt;

}
int main()
{
    vector<int>greed;
    vector<int>cookie;
    greed.push_back(1);
    greed.push_back(5);
    greed.push_back(3);
    greed.push_back(3);
    greed.push_back(4);
    cookie.push_back(4);
    cookie.push_back(2);
    cookie.push_back(1);
    cookie.push_back(2);
    cookie.push_back(1);
    cookie.push_back(3);
    cout<<cookieAssign(greed,cookie);
 return 0;
}