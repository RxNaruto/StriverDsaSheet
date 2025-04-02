class Solution {
    int maxP(vector<int>&prices,int ind,int buy,int n){
        if(ind>=n)return 0;
        if(buy){
            return max((-prices[ind]+maxP(prices,ind+1,0,n)),
            (0+maxP(prices,ind+1,1,n)));
        }else{
            return max((prices[ind]+maxP(prices,ind+2,1,n)),
            (0+maxP(prices,ind+1,0,n)));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices,0,1,n);
        
    }
};