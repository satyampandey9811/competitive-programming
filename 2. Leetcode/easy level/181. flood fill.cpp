// link to question - https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void helper(vector<vector<int>>& a, int r, int c, int val, int nc) {
        if(r < 0 or r == a.size() or c < 0 or c == a[0].size())
            return;
        if(a[r][c] != val) return;
        a[r][c] = nc;
        helper(a, r - 1, c, val, nc);
        helper(a, r + 1, c, val, nc);
        helper(a, r, c - 1, val, nc);
        helper(a, r, c + 1, val, nc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int r, int c, int nc) {
        if(a[r][c] == nc) return a;
        helper(a, r, c, a[r][c], nc);
        return a;
    }
};