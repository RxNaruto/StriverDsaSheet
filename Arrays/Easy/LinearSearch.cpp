#include<iostream>
using namespace std;
int linearSearch(int arr[],int size,int k){
    for(int i=0;i<size;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[5]={1,2,34,4,5};
    cout<<"The element 34 is present at "<<linearSearch(arr,5,34);
 return 0;
}