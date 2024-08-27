#include<iostream>
#include<vector>
using namespace std;
int calculateTotalHrs(vector<int>arr,int hourly){
    int totalH = 0;
    int n = arr.size();
    for(int i =0;i<n;i++){
        totalH+=ceil((double)arr[i]/(double)hourly);

    }
    return totalH;
    
}
int kokoEatingBanana(vector<int>arr,int h){
    int low = -1,high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        int totalH = calculateTotalHrs(arr,mid);

    }

}
int main()
{
 return 0;
}