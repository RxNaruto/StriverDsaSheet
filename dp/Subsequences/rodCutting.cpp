//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    private:
    int rod(vector<int>&price,int index,int rl){
        if(index==0){
            return price[0]*rl;
        }
        int notTake = 0+ rod(price,index-1,rl);
        int take = INT_MIN;
        int rodLen = index+1;
        if(rodLen<=rl){
            take = price[index]+rod(price,index,rl-rodLen);
        }
        return max(take,notTake);
        
        
    }
  public:
    int cutRod(vector<int> &price) {
        int size = price.size();
        return rod(price,size-1,size);
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends