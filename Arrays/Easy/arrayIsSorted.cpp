#include<iostream>
using namespace std;
bool arrayIsSorted(int arr[],int size){
    for(int i=1;i<size;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
int main()
{
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={5,4,6,2,1};
    cout<<"The array 1 is "<<arrayIsSorted(arr1,5)<<endl;
    cout<<"The array 2 is "<<arrayIsSorted(arr2,5);

 return 0;
}