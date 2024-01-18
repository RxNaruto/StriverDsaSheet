#include<iostream>
using namespace std;
int maximum(int arr[],int size){
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }

    }
    return max;
}
int numberAppearanceOnce(int arr[],int size){
    int max = maximum(arr,size);
    int array[max]={0};
    for(int i=0;i<size;i++){
        int val=arr[i];
        array[val]=array[val]+1;

        
    }
    for(int i=0;i<max;i++){
        if(array[i]==1){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[5]={1,1,2,2,3};
    cout<<"The number that appear once is "<<numberAppearanceOnce(arr,5);
 return 0;
}