// link to question - https://leetcode.com/problems/word-search/

class Solution {
public:
    int m, n;
    
    bool dfs(int pos, int i, int j, vector<vector<char>>& a, string& word) {
        if(i < 0 or j < 0 or i == m or j == n or a[i][j] == '.' or a[i][j] != word[pos]) return 0;
        if(pos == word.size() - 1) return 1;
        char temp = a[i][j];
        a[i][j] = '.';
        bool ans = dfs(pos+1, i-1, j, a, word) or dfs(pos+1, i+1, j, a, word) or
                   dfs(pos+1, i, j-1, a, word) or dfs(pos+1, i, j+1, a, word);
        a[i][j] = temp;
        return ans;
    }
    
    bool exist(vector<vector<char>>& a, string word) {
        m = a.size(), n = a[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == word[0]) {                    
                    if(dfs(0, i, j, a, word)) return 1;
                }
            }
        }
        return 0;
    }
};