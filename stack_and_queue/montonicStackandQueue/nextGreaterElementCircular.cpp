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
    vector<int>arr = {3,10,4,2,1,2,6,1,7,2,9};
    vector<int>nge = nextGreater(arr);
    for(int i=0;i<nge.size();i++){
        cout<<nge[i]<<" ";
    }

 return 0;
}