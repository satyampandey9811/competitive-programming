// link to question - https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class Solution {
public:
    int mostWordsFound(vector<string>& a) {
        int n = a.size(), ans = 0, c;
        for (int i = 0; i < n; i++) {
            c = 0;
            for (int j = 0; j < a[i].size(); j++) {
                if (a[i][j] == ' ') c++;
            }
            c++;
            ans = max(ans, c);
        }
        return ans;
    }
};