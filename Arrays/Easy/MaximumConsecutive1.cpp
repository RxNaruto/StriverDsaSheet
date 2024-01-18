#include<iostream>
using namespace std;
int maxi(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int maxconsecutive(int arr[],int size){
    int max=0,count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1){
            count++;
            max=maxi(max,count);
        }
        else{
            count=0;
        }

        

    }
    return max;
}
int main()
{
    int arr[7]={1,1,0,5,1,1,1};
    cout<<"The maximum consecutive 1s"<<maxconsecutive(arr,7);
 return 0;
}