#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>countSubarray(vector<int>arr,int k){
    int size = arr.size();
    vector<vector<int>>ans;
    for(int i=0;i<size-1;i++){
        int sum = arr[i];
        for(int j=i+1;j<size;j++){
            sum+=arr[j];
            if(sum==k){
             vector<int>temp;
             for(int k=i;k<=j;k++){
                temp.push_back(arr[k]);
             }
             ans.push_back(temp);
             
            }

        }
    }
    return ans;

}

int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    vector<vector<int>>ans=countSubarray(arr,6);
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    
}