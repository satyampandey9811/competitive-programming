// link to question - https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26), b(26);
        int ans = 0;
        for (auto &i :s) a[i - 'a']++;
        for (auto &i :t) b[i - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (a[i] or b[i]) {
                ans += max(a[i], b[i]) - min(a[i], b[i]);
            }
        }
        return ans;
    }
};