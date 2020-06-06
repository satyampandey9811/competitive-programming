// link to question - https://leetcode.com/problems/target-sum/

class Solution {
public:
    int dp[2002][21];    
    
    int f(vector<int>& a, int currsum, int i, int& t) {
        if(i == a.size()) {
            if(currsum == t) return 1;
            return 0;
        } 
        int &res = dp[currsum + 1000][i];
        if(res != -1) return res;                
        int x = f(a, currsum + a[i], i + 1, t);
        int y = f(a, currsum - a[i], i + 1, t);
        return res = x + y;
    }
    
    int findTargetSumWays(vector<int>& a, int t) {        
        memset(dp, -1, sizeof dp);
        return f(a, 0, 0, t);        
    }
};