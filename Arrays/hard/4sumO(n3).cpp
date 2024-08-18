#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>>fourSum(vector<int>arr,int target){
    int size = arr.size();
    set<vector<int>>st;
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            set<int>hashSet;
            for(int k=j+1;k<size;k++){
                int sum = arr[i]+arr[j];
                sum+=arr[k];
                int fourth = target - sum;
                if(hashSet.find(fourth)!=hashSet.end()){
                    vector<int>temp = {arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);

                }
                hashSet.insert(arr[k]);
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