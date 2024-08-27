#include<iostream>
using namespace std;
int func(int mid ,int n ,int m){
    int ans =1;
    for(int i=0;i<n;i++){
        ans=ans*mid;
        if(ans>m)return 2;
        
    }
    if(ans==m)return 1;
    return 0;

}
int nthRoot(int n,int m){
    int low = 0;
    int high = m;
    while(low<=high){
        int mid = (low+high)/2;
        int ans = func(mid,n,m);
        if(ans == 1)return mid;
        else if(ans==0){
            low = mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return -1;
}
int main()
{
    int n =4,m=69;
    cout<<nthRoot(n,m);
 return 0;
}