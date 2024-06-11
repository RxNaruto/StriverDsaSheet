//linearSearch method

#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int k){
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==k){
            count++;
        }
    }
    return count;
}

int numberAppearingOnce(int arr[],int size){
    for(int i=0;i<size;i++){
        int count=linearSearch(arr,size,arr[i]);
        if(count!=2){
            return arr[i];
        }
    }
}
int main()
{
    int arr1[3]={2,2,1};
    int arr2[5]={4,1,2,1,2};
    
    cout<<"The number appearing once in arr1 is "<<numberAppearingOnce(arr1,3)<<endl;
    cout<<"The number appearing once in arr2 is "<<numberAppearingOnce(arr2,3);
 return 0;
}