// link to question - https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        set<int> s;
        vector<vector<int>> b(m + 1, vector<int>(n + 1));
        vector<vector<int>> c(m + 1, vector<int>(n + 1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                b[i+1][j] = a[i][j];
                c[i+1][j+1] = a[i][j];
                s.insert(a[i][j]);
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j < n; j++) {
                b[i][j] += b[i-1][j+1];
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                c[i][j] += c[i-1][j-1];
            }
        }
        
        for(int ct = 3; ct <= 100; ct += 2) {
            if(ct > m or ct > n) break;
            
            for(int i = 0; i + ct <= m; i++) {
                for(int j = ct / 2; j + ct / 2 < n; j++) {
                    int len = ct / 2 + 1;
                    int first = b[i+len][j-ct/2] - b[i][j+1];
                    int second = b[i+ct][j] - b[i + ct/2][j + ct/2 + 1];
                    int third = c[i+len][j+len] - c[i][j];
                    int four = c[i+ct][j+1] - c[i+len-1][j-ct/2];
                    
                    s.insert(first + second + third + four - a[i][j] - a[i+ct-1][j] - a[i+ct/2][j-ct/2] - a[i+ct/2][j+ct/2]);
                }
            }
        }
        
        vector<int> ans;
        if(s.size()) {
            ans.push_back(*s.rbegin());
            s.erase(*s.rbegin());
        }
        if(s.size()) {
            ans.push_back(*s.rbegin());
            s.erase(*s.rbegin());
        }
        if(s.size()) {
            ans.push_back(*s.rbegin());
            s.erase(*s.rbegin());
        }
        return ans;
    }
};