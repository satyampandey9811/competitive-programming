// link to question - https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

class Solution {
public:
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& rc, vector<int>& cc) {
        
        int m = rc.size();
        int n = cc.size();
        int ans = 0;
        
        if (sp[0] < hp[0]) {
            for (int i = sp[0]; i != hp[0]; i++) {
                ans += rc[i+1];
            }
        }
        else {
            for (int i = sp[0]; i != hp[0]; i--) {
                ans += rc[i-1];
            }
        }
        
        if (sp[1] < hp[1]) {
            for (int i = sp[1]; i != hp[1]; i++) {
                ans += cc[i+1];
            }
        }
        else {
            for (int i = sp[1]; i != hp[1]; i--) {
                ans += cc[i-1];
            }
        }
        
        return ans;
    }
};