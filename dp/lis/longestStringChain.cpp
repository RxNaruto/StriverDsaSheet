class Solution {
    private:
     bool compare(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();
        int i=0,j=0;
        if(s1.size()!=s2.size()+1)return false;
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                i++;j++;
            }
            else{
                i++;
            }
        }
        if(i==n && j==m)return true;
        return false;
     }
     static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
     }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(words.size(),1);
           int lastIndex=0;
           int maxi = 1;
           for(int i=0;i<n;i++){
               for(int prev=0;prev<i;prev++){
                   if(compare(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                       dp[i]=1+dp[prev];
                      
                   }
               }
               if(dp[i]>maxi){
                   maxi = dp[i];
                   lastIndex = i;
               }
               
        }
        return maxi;
        
    }
};