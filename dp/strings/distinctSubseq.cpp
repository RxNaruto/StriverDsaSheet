class Solution {
    int dist(string s,string t,int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;

        if(s[i]==t[j]){
            return dist(s,t,i-1,j-1)+dist(s,t,i-1,j);
        }
        else{
            return dist(s,t,i-1,j);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        return dist(s,t,n-1,m-1);
        
        
    }
};