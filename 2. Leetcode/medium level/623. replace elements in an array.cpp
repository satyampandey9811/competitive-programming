// link to question - https://leetcode.com/problems/replace-elements-in-an-array/

class Solution {
public:
    vector<int> arrayChange(vector<int>& a, vector<vector<int>>& op) {
        int n = a.size();
        map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[a[i]] = i;
        }
        
        int x, y, j, len = op.size();
        
        for (int i = 0; i < len; i++) {
            y = op[i][1];
            x = op[i][0];
            j = mp[x];
            a[j] = y;
            mp[y] = j;
        }
        
        return a;
    }
};