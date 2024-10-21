#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>asteroidCollison(vector<int>arr){
    stack<int>st;
    int size = arr.size();
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            st.push(arr[i]);
        }
        else{
            while(!st.empty() && st.top()>0 && st.top()< abs(arr[i])){
                st.pop();
            }
            if(!st.empty() && st.top()==abs(arr[i])){
                st.pop();
            }
            else if(st.empty() || st.top()<0){
                st.push(arr[i]);
            }
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();

    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int>arr;
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(-5);
    vector<int>ans = asteroidCollison(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
 return 0;
}