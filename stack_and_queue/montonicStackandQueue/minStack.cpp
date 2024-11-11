#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MinStack{
    stack<pair<int,int> >st;
    public:
    void push(int val){
        int minE;
        if(st.empty()){
            minE = val;
        }
        else{
            minE = min(val,st.top().second);
        }
        st.push({val,minE});

    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }

    
};
int main()
{
    MinStack ms;
    ms.push(12);
    ms.push(15);
    ms.push(10);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    cout<<ms.top();
 return 0;
}