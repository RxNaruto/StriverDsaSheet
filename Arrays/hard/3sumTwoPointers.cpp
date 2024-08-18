#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>threeSum(vector<int>arr){
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    int size = arr.size();
    for(int i=0;i<size;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        int j=i+1;
        int k=size-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                 k--;
            }
            else{
                vector<int>temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k]==arr[k+1])k--;


            }
        }

    }
    return ans;
}
int main()
{
     vector<int>arr;
    arr.push_back(-1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(-1);
    arr.push_back(4);
    vector<vector<int>>ans=threeSum(arr);
  
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j<ans[i].size()-1)cout<<",";
        }
        cout<<"]";
    }
 return 0;
}