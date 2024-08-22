#include<iostream>
#include<vector>
using namespace std;
void repeatingAndMissing(vector<int>arr){
    int size = arr.size();
    int maxEl=*max_element(arr.begin(),arr.end());
    int repeating,missing;
    vector<int>hash(maxEl+1,0);
    for(int i=0;i<size;i++){
        hash[arr[i]]++;
    }
    for(int i=1;i<hash.size();i++){
        if(hash[i]==2){
            repeating= i;

        }
        else if(hash[i]==0){
            missing = i;
        }
    }
    cout<<"repeating :"<<repeating;
    cout<<"missing :"<<missing;
}
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    repeatingAndMissing(arr);
 return 0;
}