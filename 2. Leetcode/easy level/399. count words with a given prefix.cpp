// link to question - https://leetcode.com/problems/counting-words-with-a-given-prefix/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, len = pref.size();
        for (auto &i :words) {
            if (i.substr(0, len) == pref) ans++;
        }
        return ans;
    }
};