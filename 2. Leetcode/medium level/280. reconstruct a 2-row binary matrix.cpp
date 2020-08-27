// link to question - https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& csum) {
        vector<vector<int>> ans;
        if(u + l != accumulate(csum.begin(), csum.end(), 0)) return ans;
        
        int two = count(csum.begin(), csum.end(), 2);
        if(two > u or two > l) return ans;
        
        int n = csum.size();
        ans.resize(2, vector<int>(n));
        
        for(int i = 0; i < n; i++) {
            if(csum[i] == 2) ans[0][i] = ans[1][i] = 1, u--, l--;
            else if(csum[i]) {
                if(u <= l) ans[1][i] = 1, l--;
                else ans[0][i] = 1, u--;
            }
        }
        
        return ans;
    }
};