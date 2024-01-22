#include<iostream>
using namespace std;
int twoSum(int arr[],int size,int target){
    for(int i=0;i<size-1;i++){
        for(int j=i;j<size;j++){
            if((arr[i]+arr[j])==target){
                cout<<"Yes"<<endl;
                cout<<"The index is "<<i<<" "<<j<<endl;
                return 1;
                break;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[5]={2,6,5,8,11};
    cout<<twoSum(arr,5,14);
 return 0;
}