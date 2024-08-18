#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int>>fourSum(vector<int>arr,int target){
    set<vector<int>>st;
    int size = arr.size();
    for(int i=0;i<size-3;i++){
        for(int j=i+1;j<size-2;j++){
            for(int k=j+1;k<size-1;k++){
                for(int l=k+1;l<size;l++){
                    int sum = arr[i]+arr[j]+arr[k]+arr[l];
                    if(sum==target){
                        vector<int>temp ={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
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