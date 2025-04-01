class Solution {
    private:
    int maxP(vector<int>&prices,int ind,int buy,int n){
        if(ind==n)return 0;
        int profit = 0;
        if(buy){
            profit= max((-prices[ind]+maxP(prices,ind+1,0,n)),
            (0+maxP(prices,ind+1,1,n)));
        }
        else{
            profit= max((prices[ind]+maxP(prices,ind+1,1,n)),
            (0+maxP(prices,ind+1,0,n)));
        }
        return profit;
    }
    

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return maxP(prices,0,1,n);
        
        
    }
};