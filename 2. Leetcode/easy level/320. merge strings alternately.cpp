// link to question - https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string a, string b) {
        string ans;
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        while(i < m and j < n) {
            ans += a[i++];
            ans += b[j++];
        }
        while(i < m) ans += a[i++];
        while(j < n) ans += b[j++];
        return ans;
    }
};