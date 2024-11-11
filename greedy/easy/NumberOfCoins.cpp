#include<iostream>
using namespace std;
vector<int> coins(int n,vector<int>notes){
    int cnt=0;
    vector<int>ans;
    int i = notes.size()-1;
    while(i>=0){
        if(n==0){
            break;
        }
        if(notes[i]>n){
            i--;
        }
        else{
            ans.push_back(notes[i]);
            n=n-notes[i];
            cnt++;
            i--;

        }
    }
    return ans;
    
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(50);
    arr.push_back(100);
    arr.push_back(500);
    arr.push_back(1000);
    vector<int>ans = coins(121,arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
 return 0;
}