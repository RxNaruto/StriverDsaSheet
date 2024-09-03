#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;
int sumByD(vector<int>arr,int d){
    int size = arr.size();
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+=ceil(double(arr[i])/double(d));
    }
    return sum;

}
int smallestDivisor(vector<int>arr,int target){
    int size =arr.size();
    int maxN = *max_element(arr.begin(),arr.end());
    int low = 1;
    int high = maxN-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(sumByD(arr,mid)<=target){
            high = mid-1;
        }
        else{
            low = mid+1;

        }
        

        
    }
    return low;

}

int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    cout<<smallestDivisor(arr,8);
 return 0;
}