#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>&arr){
    int size = arr.size();
    int i=0;
    for(int j=1;j<size;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;

}
int main()
{
     vector<int>arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    int k = removeDuplicates(arr);
     for(int i=0;i<k;i++){
      cout<<arr[i]<<" ";

   }
 return 0;
}