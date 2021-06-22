// link to question - https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& a) {
        int ans = 0, m = s.size(), n = a.size();
        vector<vector<int>> c(26);
        for(int i = 0; i < m; i++) {
            c[s[i] - 'a'].push_back(i);
        }
        
        bool f;
        int e, ind;
        for(int i = 0; i < n; i++) {
            f = true, e = -1;
            for(int j = 0; j < a[i].size(); j++) {
                ind = a[i][j] - 'a';
                auto it = lower_bound(c[ind].begin(), c[ind].end(), e + 1);
                if(it == c[ind].end()) {
                    f = false;
                    break;
                }
                e = *it;
            }
            if(f) ans++;
        }
        
        return ans;
    }
};