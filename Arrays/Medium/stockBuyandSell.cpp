#include<iostream>
using namespace std;
int stockBuyandSell(int arr[],int size){
    int min=INT_MAX;
    int max=INT_MIN;
    int ind=-1;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
            ind=i;
        }
    }
    if(ind==size-1){
        return 0;
    }
    else{
        
        for(int i=ind+1;i<size;i++){
            if(arr[i]>max){
                max= arr[i];
                
            }
        }
    }
    return max-min;


}
int main()
{
    int arr[5]={7,6,4,3,1};
    cout<<stockBuyandSell(arr,5);
 return 0;
}