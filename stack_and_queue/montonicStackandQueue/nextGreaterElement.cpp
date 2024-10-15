#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>nextGreater(vector<int>arr){
    stack<int>st;
    vector<int>ans;
    for(int i=arr.size()-1;i>=0;i--){
        if(st.empty()){
            ans.push_back(-1);
            st.push(arr[i]);
        }
        else{
            while(st.top()<arr[i] || !st.empty()){
            st.pop();
            }
            if(!st.empty()){
            ans.push_back(st.top());
            st.push(arr[i]);
            }
            else{
                ans.push_back(-1);
                st.push(arr[i]);
            }
    }
    
}
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(10);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(9);
    vector<int>ans  = nextGreater(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

 return 0;
}