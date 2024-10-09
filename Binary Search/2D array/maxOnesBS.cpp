#include<iostream>
#include<vector>
using namespace std;
int maxOnes(vector<vector<int>>arr){
    int ans;
    int max;
    for(int i=0;i<arr.size();i++){
        int low = 0;
        int high = arr[i].size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[i][mid]>=1){
                ans=mid;
                high=mid-1;

            }
            else{
                low = mid+1;
            }

        }
        max = arr[i].size()-ans;
    }
}
int main()
{
 return 0;
}