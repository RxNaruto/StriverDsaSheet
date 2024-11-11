#include<iostream>
#include<vector>
#include<map>
using namespace std;
int fruitBasket(vector<int>arr,int k){
    int size = arr.size();
    int l=0,r=0,maxLen = INT_MIN;
    map<int,int>mp;
    while(r<size){
        mp[arr[r]]++;
        if(mp.size()>k){
            while(mp.size()>k){
                mp[arr[l]]--;
                if(mp[arr[l]]==0)mp.erase(arr[l]);
                l++;
            }
            
            

        }
        if(mp.size()<=k){
            maxLen = max(maxLen,(r-l+1));
        }
        r++;
    }
    return maxLen;
}
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);

    cout<<fruitBasket(arr,2);
 return 0;
}