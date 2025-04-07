//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    int mat(vector<int>&arr,int i,int j){
        if(i==j)return 0;
        int mine = 1e9;
        for(int k=i;k<j;k++){
            int steps = (arr[i-1]*arr[k]*arr[j])+
            mat(arr,i,k)+mat(arr,k+1,j);
            mine = min(mine,steps);
        }
        return mine;
        
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        return mat(arr,1,arr.size()-1);
        // code here
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends