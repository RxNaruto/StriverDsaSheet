#include<iostream>
#include<vector>
using namespace std;
void unionSet( vector<int>&arr1,vector<int>&arr2){
    int i=0,j=0;
    int s1=arr1.size();
    int s2=arr2.size();
    vector<int>uArr;
    while(i<s1 && j<s2){
        if(arr1[i]<=arr2[j]){
            if(uArr.size()==0 || uArr.back()!=arr1[i]){
             uArr.push_back(arr1[i]);
        }
       
            i++;
        }
        else{
           
            if(uArr.size()==0 || uArr.back()!=arr2[j]){
             uArr.push_back(arr2[j]);
        }
       
            j++;
       
        }

    }
    while(j<s2){
         if(uArr.size()==0 || uArr.back()!=arr2[j]){
             uArr.push_back(arr2[j]);
        }
       
            j++;
       
        
        

    }
    while(i<s1){
        if(arr1[i]<=arr2[j]){
            if(uArr.size()==0 || uArr.back()!=arr1[i]){
             uArr.push_back(arr1[i]);
        }
       
            i++;
        }
    }
    for(i=0;i<uArr.size();i++){
        cout<<uArr[i]<<" ";
    }
}
int main()
{
    vector<int>arr1 = {1,2,3,4,5,6,7,8,9,10};
vector<int>arr2 = {2,3,4,4,5,11,12};
unionSet(arr1,arr2);
 return 0;
}