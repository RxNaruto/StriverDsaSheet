#include<iostream>
#include<vector>
using namespace std;
vector<int> majorityElement(vector<int>arr){
    vector<int>ans;
    int size = arr.size();
    int el1,el2;
    int cnt1=0,cnt2=0;
    for(int i=0;i<size;i++){
        if(cnt1==0 && el2!=arr[i]){
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && el1!=arr[i]){
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1){
            cnt1++;
        }
        else if(arr[i]==el2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    int ncnt1=1;
    int ncnt2=1;
    for(int i=0;i<size;i++){
        if(arr[i]==el1){
            ncnt1++;
        }
        else if(arr[i]==el2){
            ncnt2++;
        }
    }
    if(ncnt1>(size/3)){
      ans.push_back(el1);
    }
    if(ncnt2>(size/3)){
        ans.push_back(el2);
    }
    return ans;
}
int main()
{
    vector<int>arr;
    arr.push_back(11);
    arr.push_back(33);
    arr.push_back(33);
    arr.push_back(11);
    arr.push_back(33);
    arr.push_back(11);
    vector<int>ans=majorityElement(arr);
    for(auto itr: ans){
        cout<<itr<<" ";
    }
    

 return 0;
}