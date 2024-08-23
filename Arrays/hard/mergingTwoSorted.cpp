#include<iostream>
#include<vector>
using namespace std;
void mergeTwoSorted(vector<int>&arr1,vector<int>&arr2){
    int s1=arr1.size();
    int s2=arr2.size();
    int i=0,j=0,k=0;
    vector<int>arr3(s1+s2);
    while(i<s1 && j<s2){
        if(arr1[i]<arr2[j]){
            arr3[k]=arr1[i];
            i++;k++;
        }
        else{
            arr3[k]=arr2[j];
            j++;k++;
        }

    }
    while(i<s1){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<s2){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    for(int i=0;i<s1;i++){
        arr1[i]=arr3[i];
    }
    for(int j=0;j<s2;j++){
        arr2[j]=arr3[s1+j];
    }
}
int main()
{
    vector<int>arr1 = {1,4,8,10};
    vector<int>arr2 = {2,3,9};
    mergeTwoSorted(arr1,arr2);
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
 return 0;
}