// link to question - https://leetcode.com/problems/perfect-squares/

int dp[10000];
int i = 1;

class Solution {
public:
    int numSquares(int n) {
        dp[0] = 0;                
        while(i <= n) {
            int val = INT_MAX;            
            for(int j = 1; j * j <= i; j++) {
                val = min(val , 1 + dp[i - j * j]);
            }            
            dp[i] = val;            
            i++;
        }
        return dp[n];
    }
};