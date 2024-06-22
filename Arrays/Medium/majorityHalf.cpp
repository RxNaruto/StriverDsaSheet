#include<iostream>
using namespace std;
int majorityHalf(int arr[],int size,int n){
    int target=n/2;
    
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>target){
            return arr[i];
        }
    
        
    }
    return -1;
}
int main()
{
    int arr[7]= {2,2,1,1,1,2,2}
;
    cout<<majorityHalf(arr,7,7);
 return 0;
}