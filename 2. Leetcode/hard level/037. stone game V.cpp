// link to question - https://leetcode.com/problems/stone-game-v/

class Solution {
public:
    int n;
    vector<int> a;
    int dp[501][501];
    
    int go(int s, int e) {
        if(s >= e) return 0;
        int &ans = dp[s][e];
        
        if(ans != -1) return ans;
        
        ans = 0;        
        int suml = 0, sumr = 0;
        
        for(int i = s; i <= e; i++) sumr += a[i];
        
        for(int i = s; i <= e; i++) {
            suml += a[i];
            sumr -= a[i];
            if(suml < sumr) {
                ans = max(ans, suml + go(s, i));
            }
            else if(suml == sumr) {
                ans = max({ans, suml + go(s, i), sumr + go(i + 1, e)});
            }
            else {
                ans = max(ans, sumr + go(i + 1, e));
            }
        }
        
        return ans;
    }
    
    int stoneGameV(vector<int>& stones) {        
        a = stones;
        n = a.size();
        memset(dp, -1, sizeof dp);
        return go(0, n - 1);
    }
};