class Solution {
    bool match(string s,string p,int i,int j){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0)return false;
        if(j<0 && i>=0){
            for(int ind=0;ind<=i;ind++){
                if(s[ind]!='*')return false;
            }
            return true;
        }
        if((s[i]==p[j]) || s[i]=='?' ) return match(s,p,i-1,j-1);
        if(s[i]=='*'){
            return match(s,p,i-1,j) || match(s,p,i,j-1);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return match(p,s,m-1,n-1);
        
    }
};