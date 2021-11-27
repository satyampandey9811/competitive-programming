// link to question - https://leetcode.com/problems/count-common-words-with-one-occurrence/

class Solution {
public:
    int countWords(vector<string>& a, vector<string>& b) {
        map<string, int> x, y;
        for (auto &i :a) x[i]++;
        for (auto &i :b) y[i]++;
        
        int n = a.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (x[a[i]] == 1 and y[a[i]] == 1) ans++;
        }
        
        return ans;
    }
};