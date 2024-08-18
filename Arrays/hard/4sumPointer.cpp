#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>>fourSum(vector<int>arr,int target){
    int size = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<size;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<size;j++){
            if(j!=i+1 && arr[j]==arr[j-1])continue;
            int k=j+1;
            int l=size-1;
            while(k<l){
                int sum = arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum==target){
                    vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])k++;
                    while(k<l && arr[l]==arr[l+1])l--;
                    
                }
                else if(sum>target){
                  l--;
                }
                else{
                    k++;
                }
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
    arr.push_back(0);
    arr.push_back(-2);
    arr.push_back(2);
    vector<vector<int>>ans=fourSum(arr,0);
  
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