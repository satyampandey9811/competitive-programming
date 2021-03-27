// link to question - https://leetcode.com/problems/word-subsets/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<string> ans;
        int m = a.size(), n = b.size();
        
        vector<vector<int>> u(m, vector<int>(26)), v(n, vector<int>(26));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < a[i].size(); j++) {
                u[i][a[i][j] - 'a']++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < b[i].size(); j++) {
                v[i][b[i][j] - 'a']++;
            }
        }
        
        vector<int> z(26);
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < n; j++) {
                z[i] = max(z[i], v[j][i]);
            }
        }
        
        for(int i = 0; i < m; i++) {
            bool f = true;
            for(int j = 0; j < 26; j++) {
                if(u[i][j] < z[j]) {
                    f = false;
                    break;
                }
            }
            if(f) ans.push_back(a[i]);
        }
        
        return ans;
    }
};