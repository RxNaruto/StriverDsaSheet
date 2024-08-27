#include<iostream>
using namespace std;
int sqrtOfNum(int num){
    int low = 0;
    int high = num;
    while(low<=high){
        int mid = (low+high)/2;
        long long val = mid*mid;
        if(val<=(long long)(num)){
            low = mid+1;
        }
        else{
             high = mid-1;
        }
    }
    return high;
}
int main()
{
    cout<<sqrtOfNum(36);
 return 0;
}