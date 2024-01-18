#include<iostream>
using namespace std;
int LinearSearch(int arr[],int size,int ele){
    for(int i=0;i<size;i++){
        if(arr[i]==ele){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[5]={1,20,3,4,5};
    cout<<"The element 20 is present at "<<LinearSearch(arr,5,20)<<" index";
 return 0;
}