#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>>threeSum(vector<int>arr){
    int size = arr.size();
    set<vector<int>>st;
    for(int i=0;i<size;i++){
        set<int>hashSet;
        for(int j =i+1;j<size;j++){
            int third = -(arr[i]+arr[j]);
            if(hashSet.find(third)!=hashSet.end()){
                vector<int>temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
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