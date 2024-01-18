#include<iostream>
using namespace std;
int missingElement(int arr[],int size){
    int missingElement=arr[0];
    for(int i=1;i<size;i++){
        missingElement++;
        if(arr[i]!=missingElement){
            return missingElement;
        }
    }
    return -1;
}
int main()
{
    int arr[5]={1,2,3,5,6};
    cout<<"THe missing element is"<<missingElement(arr,5);
 return 0;
}