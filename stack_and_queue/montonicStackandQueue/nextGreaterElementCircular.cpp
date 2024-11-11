#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>nextGreater(vector<int>arr){
    int size = arr.size();
    vector<int>nge(size,-1);
    stack<int>st;
    for(int i=2*size-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i%size]){
            st.pop();
        }
        if(i<size){
            if(!st.empty()) nge[i]=st.top();
        }
        st.push(arr[i%size]);
    }
    return nge;
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
    vector<int>nge = nextGreater(arr);
    for(int i=0;i<nge.size();i++){
        cout<<nge[i]<<" ";
    }

 return 0;
}