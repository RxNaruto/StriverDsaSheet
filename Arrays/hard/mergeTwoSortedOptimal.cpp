#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void mergeTwoSort(vector<int>&arr1,vector<int>&arr2){
    int s1= arr1.size();
    int s2= arr2.size();
    int left = s1-1;
    int right= 0;
    while(left>=0 && right<s2){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;

        }
        else{
            break;
        }
        
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    
}
int main()
{
     vector<int>arr1 = {1,4,8,10};
    vector<int>arr2 = {2,3,9};
    mergeTwoSort(arr1,arr2);
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
 return 0;
}