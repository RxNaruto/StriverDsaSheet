#include<iostream>
using namespace std;
int missingNumber(int arr[],int size){
    for(int i=1;i<size;i++){
        if(arr[i]!=(arr[i-1]+1)){
            return arr[i]-1;
        }
    }
return -1;
}
int main()
{
    int arr[4]={1,2,4,5};
    cout<<"The missing number is "<<missingNumber(arr, 4);
 return 0;
}