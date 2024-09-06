#include <algorithm>
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int checkPages(vector<int>arr,int pages){
    int std = 1,pagesStudent=0;
    int size = arr.size();
    for(int i=0;i<size;i++){
        if(pagesStudent+arr[i]<=pages){
            pagesStudent+=arr[i];
        }
        else{
            std++;
            pagesStudent=arr[i];
        }
    }
    return std;
}
int bookAllocation(vector<int>arr,int students){
    int size = arr.size();
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    for(int i = low;i<=high;i++){
        if(checkPages(arr,i)==students){
            return i;
        }
    }
    return -1;

}
int main()
{
    vector<int>arr;
    arr.push_back(12);
    arr.push_back(34);
    arr.push_back(67);
    arr.push_back(90);
    int std = 2;
    cout<<bookAllocation(arr,std);
 return 0;
}