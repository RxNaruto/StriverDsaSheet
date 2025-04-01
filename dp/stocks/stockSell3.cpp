class Solution {
    int maxP(vector<int>&prices,int ind,int buy,int cap,int n){
        
        if(ind==n || cap==0)return 0;
        if(buy){
            return max((-prices[ind]+maxP(prices,
            ind+1,0,cap,n)),(0+maxP(prices,ind+1,1,cap,n)));
        }
        else{
            return max((prices[ind]+maxP(prices,
            ind+1,1,cap-1,n)),(0+maxP(prices,ind+1,0,cap,n)));
        }
        
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices,0,1,2,n);
        
    }
};