#include<iostream>
#include<vector>
using namespace std;
bool possible(vector<int>arr,int m,int k,int day){
    int size = arr.size();
    int count=0,botiques=0;
    for(int i=0;i<size;i++){
        if(arr[i]<=day){
            count++;
        }
        else{
            botiques+=(count/k);
            count=0;

        }
    }
    botiques+=(count/k);
    return botiques>=m;
}
int checkDay(vector<int>arr,int m,int k){
    int val = m*k;
    int size =arr.size();
    if(val>size){
        return -1;
    }
    int minN = INT_MAX;
    int maxN = INT_MIN;
    for(int i=0;i<size;i++){
        minN = min(minN,arr[i]);
        maxN = max(maxN,arr[i]);

    }
    
    int low = minN;
    int high = maxN;
    while(low<=high){
        int mid = (low+high)/2;
        if( possible(arr,m,k,mid)){
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
    int m = 2,k=3;
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(13);
    arr.push_back(11);
    arr.push_back(12);
    arr.push_back(7);
    cout<<checkDay(arr,m,k);
 return 0;
}