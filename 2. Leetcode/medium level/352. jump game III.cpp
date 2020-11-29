// link to question - https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    vector<bool> vis;
    
    bool go(vector<int>& a, int s, int& n) {
        if(s < 0 or s >= n or vis[s]) return 0;
        if(a[s] == 0) return 1;
        vis[s] = true;
        return go(a, s - a[s], n) or go(a, s + a[s], n);
    }
    
    bool canReach(vector<int>& a, int s) { 
        int n = a.size();
        vis.resize(n);
        return go(a, s, n);
    }
};