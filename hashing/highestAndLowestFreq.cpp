#include<iostream>
#include<map>
using namespace std;
int main()
{
    int arr[6]={10,5,10,15,10,5};
    map<int,int>mpp;
    for(int i=0;i<6;i++){
        mpp[arr[i]]++;

    } 
    int maxfreq= 0,minfreq=6;
    int maxEle=0,minEle=0;
    for(auto it: mpp){
        int count= it.second;
        int element= it.first;
        if(count>maxfreq){
            maxEle = element;
            maxfreq = count;
        }
        if(count<minfreq){
            minEle = element;
            minfreq=count;
        }

    }
    cout<<minEle<<endl;
    cout<<maxEle<<endl;
 return 0;
}