#include<iostream>
#include<vector>
using namespace std;
int countInversion(vector<int>arr){
    int size = arr.size();
    int count =0;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int>arr;
     arr.push_back(5);
     arr.push_back(4);
     arr.push_back(3);
     arr.push_back(2);
     arr.push_back(1);
      
       
       
        cout<<countInversion(arr);
 return 0;
}