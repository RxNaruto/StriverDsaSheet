#include<iostream>
#include<vector>
using namespace std;
int printSub(int ind,int arr[],int sum,int x,int n){
    if(ind==n){
        if(sum==x){
            return 1;  
        }
        return 0;
    }
    sum= sum+arr[ind];
    int l = printSub(ind+1,arr,sum,x,n);
    sum=sum-arr[ind];
    int r= printSub(ind+1,arr,sum,x,n);
    return l+r;

}
int main()
{
    int arr[3]={3,1,2};
    int n =3;
    int x =3;
    int sum=0;
    cout<<printSub(0,arr,sum,x,3);
 return 0;
}