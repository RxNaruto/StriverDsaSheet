#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& arr,int target){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if((arr[i]+arr[j])==target){
                cout<<"Yes"<<endl;
                return {i,j};
                break;
            }
        }
    }
    return {-1,-1};
}
int main()
{

    vector<int>arr={2,6,5,8,11};
    cout<<twoSum(arr,5);
    
 return 0;
}