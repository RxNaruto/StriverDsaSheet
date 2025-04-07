class Solution {
    private:
    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
public:
    int minCut(string s) {
        vector<int>dp(s.size()+1,0);
        dp[s.size()]=0;
        for(int i = s.size()-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int j=i;j<s.size();j++){
                if(isPalindrome(i,j,s)){
                   int cost=1+dp[j+1];
                   minCost = min(minCost,cost);
                }
            }
        dp[i]=minCost;

        }
        return dp[0]-1;
        
    }
};