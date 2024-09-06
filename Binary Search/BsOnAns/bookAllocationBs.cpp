#include <algorithm>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;
int checkStudents(vector<int>bookPages,int pages){
    int std=1,stdPages=0;
    int size = bookPages.size();
    for(int i=0;i<size;i++){
        if(stdPages+bookPages[i]<=pages){
            stdPages+=bookPages[i];
        }
        else{
            std++;
            stdPages=bookPages[i];
        }
    }
    return std;
}
int bookAllocation(vector<int>bookPages,int students){
    int size = bookPages.size();
    int low = *max_element(bookPages.begin(),bookPages.end());
    int high = accumulate(bookPages.begin(),bookPages.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        if(checkStudents(bookPages,mid)<=students){
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
    arr.push_back(12);
    arr.push_back(34);
    arr.push_back(67);
    arr.push_back(90);
    int std = 2;
    cout<<bookAllocation(arr,std);
 return 0;
}