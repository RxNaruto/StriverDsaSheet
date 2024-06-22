#include<iostream>
using namespace std;
int kadane(int arr[],int size){
    int sum=0,max=INT_MIN,start;
    int arrStart=-1,arrEnd=-1;
    for(int i=0;i<size;i++){
        if(sum==0){
            start = i;
        }
       sum+=arr[i];
       if(sum>max){
        max=sum;
        arrStart = start;
        arrEnd = i;

       }
       if(sum<0){
        sum=0;
       }
       
        
    }
    cout<<"The index of maxsubarray is"<<endl;
    cout<<arrStart<<" "<<arrEnd<<" "<<endl;
    cout<<"The max sum of subarray is"<<endl;
    return max;
}
int main()
{
     int arr[9]={-2,1,-3,4,-1,2,1,-5,4};
     cout<<kadane(arr,9)<<endl;
 return 0;
}