#include<iostream>
#include<vector>
using namespace std;
int possible(vector<int>arr,int m,int k,int day){
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
    return botiques;
}
int minDayToMake(vector<int>arr,int m,int k){
    int size = arr.size();
    int minN = INT_MAX;
    int maxN = INT_MIN;
    for(int i=0;i<size;i++){
        minN=min(arr[i],minN);
        maxN=max(arr[i],maxN);

    }
    for(int i=minN;i<=maxN;i++){
        int botiques = possible(arr,m,k,i);
        if(botiques>=m){
            return i;
        }
    }
    return -1;

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
    cout<<minDayToMake(arr,m,k);
    


 return 0;
}