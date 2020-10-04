// link to question - https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void go(vector<int>& temp, vector<int>& a, vector<bool>& vis) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            if(i > 0 and a[i] == a[i-1] and !vis[i-1]) continue;
            vis[i] = true;
            temp.push_back(a[i]);
            go(temp, a, vis);
            vis[i] = false;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        n = a.size();
        sort(a.begin(), a.end());
        vector<int> temp;
        vector<bool> vis(n);
        go(temp, a, vis);
        return ans;
    }
};