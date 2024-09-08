#include<iostream>
#include<vector>
using namespace std;
int medianOfTwoSorted(vector<int>arr1,vector<int>arr2){
    int size1 = arr1.size();
    int size2 = arr2.size();
    vector<int>arr3(size1+size2);
    int median;
    int i=0,j=0,k=0;
    while(i<size1){
        arr3[k]=arr1[i];
        i++;k++;
    }
    while(j<size2){
        arr3[k]=arr2[j];
        j++;k++;
    }
    sort(arr3.begin(),arr3.end());
    if(arr3.size()%2==0){
        median = (arr3[arr3.size()/2]+arr3[(arr3.size()/2)-1])/2;
    }
    else median = (arr3[arr3.size()/2]);

    return median;
}
int main()
{
    vector<int>arr1= {2,4,6};
    vector<int>arr2={1,3};
    cout<<medianOfTwoSorted(arr1,arr2);
 return 0;
}