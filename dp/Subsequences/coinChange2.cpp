class Solution {
    int countWays(int amount,vector<int>&coins,int index){
        if(index==0){
            if(amount%coins[0]==0)return 1;
            else return 0;
        }
         int notTake = countWays(amount,coins,index-1);
        int take = 0;
        if(coins[index]<=amount){
            take = countWays(amount-coins[index],coins,index);
        }
        return take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        return countWays(amount,coins,coins.size()-1);
        
    }
};