#include<iostream>
using namespace std;
int numberAppearance(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
}
int main()
{
    int arr[5]={2,1,4,1,2};
    cout<<"The number that appear twice is"<<numberAppearance(arr,5);
 return 0;
} 