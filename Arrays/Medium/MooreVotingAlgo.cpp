#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>arr){
    int count=0;
    int ele;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            count=1;
            ele=arr[i];
        }
        else if(arr[i]==ele){
            count++;
        }
        else{
            count--;
        }
    }
    int count1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==ele){
            count1++;
        }
    }
    if(count1>(arr.size()/2)){
        return ele;
    }
    return -1;
    
}

int main()
{
    vector<int>arr= {2,2,1,1,1,2,2};
    cout<<majorityElement(arr);
 return 0;
}