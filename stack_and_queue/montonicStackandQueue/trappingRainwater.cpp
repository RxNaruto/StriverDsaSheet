#include<iostream>
#include<vector>
using namespace std;
int trappingRainWater(vector<int>arr){
    int size = arr.size();
    int prefix[size],suffix[size];
    prefix[0]=arr[0];
    for(int i=1;i<size;i++){
        prefix[i]=max(prefix[i-1],arr[i]);
    }
    suffix[size-1]=arr[size-1];
    for(int i=size-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],arr[i]);
    }
    int waterTrapped=0;
    for(int i=0;i<size;i++){
        waterTrapped+=min(prefix[i],suffix[i])-arr[i];
    }
    return waterTrapped;
}

int main()
{
    vector<int>arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);

    cout<<trappingRainWater(arr);
 return 0;
}