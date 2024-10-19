#include<iostream>
#include<vector>
using namespace std;
vector<int>moveZeros(vector<int>&arr){
    int size = arr.size();
    int j=-1;
    for(int i=0;i<size;i++){
        if(arr[i]==arr[j]){
            j=i;
            break;
        }
    }
    if(j==-1)return arr;

    for(int i=j+1;i<size;i++){
        if(arr[i]!=0){
            swap(arr[j],arr[i]);
            j++;
        }
    }
    return arr;

}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(0);
    arr.push_back(1);
    vector<int>narr =moveZeros(arr);
    for(int i=0;i<narr.size();i++){
        cout<<narr[i]<<" ";
    }
 return 0;
}