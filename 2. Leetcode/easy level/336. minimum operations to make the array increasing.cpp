// link to question - https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size(), x = a[0], ans = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] > x) {
                x = a[i];
                continue;
            }
            ans += x - a[i] + 1;
            x++;
        }
        return ans;
    }
};