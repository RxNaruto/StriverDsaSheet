#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>>threeSum(vector<int>arr){
    set<vector<int>>st;
    int size = arr.size();
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k=j+1;k<size;k++){
                if((arr[i]+arr[j]+arr[k])==0){
                   vector<int>temp = {arr[i],arr[j],arr[k]};
                   sort(temp.begin(),temp.end());
                   st.insert(temp);

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