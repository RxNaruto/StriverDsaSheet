class Solution {
    int coinsC(vector<int>&arr,int index,int amount){
        if(index==0){
            if(amount%arr[0]==0){
                return amount/arr[0];
            }
            else return 1e9;
        }
        int notTake = 0+coinsC(arr,index-1,amount);
        int take = INT_MAX;
        if(arr[index]<=amount){
            take = 1+coinsC(arr,index,amount-arr[index]);
        }
        return min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        int ans = coinsC(coins,coins.size()-1,amount);
        if(ans>=1e9)return -1;
        return ans;
        
    }
}; 