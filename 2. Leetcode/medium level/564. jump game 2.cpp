// link to question - https://leetcode.com/problems/jump-game-ii/v

class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size(), ans = 0, end = 0, val;
        int i = 0, j;
        
        while (i < n - 1) {
            ans++;
            val = i + a[i];
            for (j = i + 1; j <= val; j++) {
                if (j == n - 1) return ans;
                if (end <= j + a[j]) {
                    end = j + a[j];
                    i = j;
                }
            }
        }
        return ans;
    }
};