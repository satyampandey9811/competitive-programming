// link to question - https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n;) {
            int j = i, sum = 0, maxn = 0;
            while(j < n and s[j] == s[i]) {
                sum += cost[j];
                maxn = max(maxn, cost[j]);
                j++;
            }
            ans += sum - maxn;
            i = j;
        }
        
        return ans;
    }
};