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
    int minC(string &s,int i,int n){
        if(i==n)return 0;
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+minC(s,j+1,n);
                minCost = min(minCost,cost);
            }
        }
        return minCost;
    }
public:
    int minCut(string s) {
        return minC(s,0,s.size())-1;
        
    }
};