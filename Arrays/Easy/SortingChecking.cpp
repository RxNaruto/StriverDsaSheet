#include<iostream>
using namespace std;
int SortingChecking(int arr[],int size){
    for(int i=1;i<size;i++){
        if(!(arr[i]>arr[i-1])){
            return -1;


        }
    }
    return 1;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    cout<<"The array is "<<SortingChecking(arr,5);
 return 0;
}