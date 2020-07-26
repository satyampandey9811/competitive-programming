// link to question - https://leetcode.com/problems/shuffle-string/

class Solution {
public:
    string restoreString(string s, vector<int>& ind) {
        string a = s;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            a[ind[i]] = s[i];
        }
        return a;
    }
};