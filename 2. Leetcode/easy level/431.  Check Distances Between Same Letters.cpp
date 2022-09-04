// link to question - https://leetcode.com/problems/check-distances-between-same-letters/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> a(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (a[s[i] - 'a'] == -1) {
                a[s[i] - 'a'] = i;
            }
            else {
                if (i - a[s[i] - 'a'] - 1 != distance[s[i] - 'a']) return 0;
            }
        }
        return 1;
    }
};