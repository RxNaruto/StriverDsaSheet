#include<iostream>
#include<vector>
using namespace std;
double medianOfTwoSorted(vector<int>arr1,vector<int>arr2){
    int size1 = arr1.size();
    int size2 = arr2.size();
    int totalSize = size1+size2;
    int ind1=(totalSize/2)-1;
    int ind2=(totalSize/2);
    int indel1=-1,indel2=-1;
    
    int i=0,j=0,k=0;
    while(i<size1 && j<size2){
         if(arr1[i]<arr2[j]){
            if(k==ind1){
                indel1=arr1[i];
            }
            if(k==ind2){
                indel2= arr1[i];
            }
            i++;k++;
         }
         else{
            if(k==ind1){
                indel1=arr2[j];
            }
            if(k==ind2){
                indel2= arr2[j];
            }
            j++;k++;

         }
    }
    while(i<size1){
        if(k==ind1)indel1=arr1[i];
        if(k==ind2)indel2=arr1[i];
        i++;k++;
    }
    while(j<size2){
        if(k==ind1)indel1=arr2[j];
        if(k==ind2)indel2=arr2[j];
        j++;k++;
    }
    if(totalSize%2==0){
        return (indel1+indel2)/2.0;
    }
    else{
        return indel2;
    }
}
int main()
{
    vector<int>arr1;
    vector<int>arr2;
    arr1.push_back(2);
    arr1.push_back(4);
    arr1.push_back(6);
    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(5);
    cout<<medianOfTwoSorted(arr1,arr2);
 return 0;
}