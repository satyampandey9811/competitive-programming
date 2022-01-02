// link to question - https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string>& a) {
        int n = a.size();
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            for (auto &j :a[i]) {
                if (j == '1') b[i]++;
            }
        }
        
        int ans = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            if (b[i]) {
                if (prev == 0) prev = b[i];
                else {
                    ans += prev * b[i];
                    prev = b[i];
                }
            }
        }
        
        return ans;
    }
};