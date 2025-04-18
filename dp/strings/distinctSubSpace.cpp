class Solution {
    
    public:
        int numDistinct(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<double>prev(m+1,0),curr(m+1,0);
            prev[0]=curr[0]=1;
            
            //j will start from 1 if it starts from 0 it will overwrite
            // the prev loop condition
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==t[j-1]){
                       curr[j]=prev[j-1]+prev[j];
                    }
                    else{
                        curr[j]=prev[j];
                    }
    
                }
                prev = curr;
            }
            return (int)prev[m];
            
            
        }
    };