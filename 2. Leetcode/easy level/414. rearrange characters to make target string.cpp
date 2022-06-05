// link to question - https://leetcode.com/problems/rearrange-characters-to-make-target-string/

class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> a(26), b(26);
        for (auto &i :s) a[i - 'a']++;
        for (auto &i :t) b[i - 'a']++;
        int ans = 1e5;
        for (int i = 0; i < 26; i++) {
            if (b[i]) ans = min(ans, a[i] / b[i]);
        }
        return ans;
    }
};