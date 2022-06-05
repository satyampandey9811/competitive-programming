// link to question - https://leetcode.com/problems/min-max-game/

class Solution {
public:
    int minMaxGame(vector<int>& a) {
        if (a.size() == 1) return a[0];
        
        int n = a.size();
        vector<int> s(n / 2);
        
        for (int i = 0; i < n / 2; i++) {
            if (i % 2 == 0) {
                s[i] = min(a[2 * i], a[2 * i + 1]);
            }
            else {
                s[i] = max(a[2 * i], a[2 * i + 1]);
            }
        }
        return minMaxGame(s);
    }
};