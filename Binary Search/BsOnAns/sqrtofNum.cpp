#include<iostream>
using namespace std;
int sqrtOfNumber(int number){
    int low =0;
    int high = number-1;
 
    while(low<=high){
        int mid=(low+high)/2;
        int sqr = mid*mid;
        
        if(sqr<=number){
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
    int number = 28;
    cout<<sqrtOfNumber(number);

 return 0;
}