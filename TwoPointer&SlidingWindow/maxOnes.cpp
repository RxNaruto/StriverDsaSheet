#include<iostream>
#include<vector>
using namespace std;
int maxOnes(vector<int>arr,int k){
    int size = arr.size();
    int maxE = INT_MIN;
    int maxL = -1;
    for(int i=0;i<size;i++){
        int zeros = 0;
        for(int j=i;j<size;j++){
            if(arr[j]==0){
                zeros++;
                
            }
            if(zeros<=k){
                maxL = j-i+1;
                maxE = max(maxE,maxL);
            }
            else{
                break;

            }
            

        }
    }
    return maxE;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    cout<<maxOnes(arr,2);
 return 0;
}