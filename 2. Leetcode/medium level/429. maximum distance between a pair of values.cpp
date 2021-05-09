// link to question - https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int ans = 0, i = 0, j = 0;
        
        while(i < (int)a.size()) {
            j = max(j, i);
            while(j < (int)b.size() and a[i] <= b[j]) {
                j++;
            }
            ans = max(ans, j - 1 - i);
            i++;
        }
        
        return ans;
    }
};