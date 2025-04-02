class Solution {
    int maxP(vector<int>&prices,int ind,int buy,int n,int fee){
        if(ind==n)return 0;
        if(buy){
            return max((-prices[ind]+maxP(prices,ind+1,0,n,fee)),
            (0+maxP(prices,ind+1,1,n,fee)));
        }else{
            return max((prices[ind]-fee+maxP(prices,ind+1,1,n,fee)),
            (0+maxP(prices,ind+1,0,n,fee)));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return maxP(prices,0,1,n,fee);
        
    }
};