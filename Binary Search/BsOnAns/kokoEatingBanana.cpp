#include<iostream>
#include<vector>
using namespace std;
int kokoEatingBanana(vector<int>arr,int h){
    int size = arr.size();
    int time=0;
    int maxE = *max_element(arr.begin(),arr.end());
    int j=0;
    while(time!=h){
        time = 0;
        j++;
        for(int i =0;i<size;i++){
            if(arr[i]%j==0){
                time += arr[i]/j;

            }
            else{
                time+=arr[i]/j +1;
            }
        }


    }
    return j;

}
int main()
{
    vector<int>arr;
    arr.push_back(25);
    arr.push_back(12);
    arr.push_back(8);
    arr.push_back(14);
    arr.push_back(19);
    cout<<kokoEatingBanana(arr,5);

 return 0;
}