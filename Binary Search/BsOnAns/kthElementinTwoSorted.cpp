#include<iostream>
#include<vector>
using namespace std;
int kthElement(vector<int>arr1,vector<int>arr2,int k){
    int s1 = arr1.size();
    int s2 = arr2.size();
    int i=0,j=0,cnt=0;
    while(i<s1 && j<s2){
        if(arr1[i]<arr2[j]){
            if(k==cnt+1){
                return arr1[i];
            }
            i++;cnt++;
        }
        else{
           if(cnt+1==k){
                return arr2[j];
            }
            j++;cnt++; 
        }
    }
    while(i<s1){
        if(cnt+1==k)return arr1[i];
        cnt++,i++;
    }
    while(j<s2){
        if(cnt+1==k)return arr2[j];
        cnt++,j++;
    }
    return -1;
}
int main()
{
    vector<int>arr1;
    vector<int>arr2;
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(6);
    arr1.push_back(7);
    arr1.push_back(9);
    arr2.push_back(1);
    arr2.push_back(4);
    arr2.push_back(8);
    arr2.push_back(10);
    cout<<kthElement(arr1,arr2,5);

 return 0;
}