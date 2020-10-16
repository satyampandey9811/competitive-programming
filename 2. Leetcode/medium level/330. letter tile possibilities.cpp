// link to question - https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
public:
    int n;    
    set<string> s;
    
    void go(string w, string& a, vector<bool> vis) {
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            go(w + a[i], a, vis);
            vis[i] = false;
        }
        s.insert(w);
    }
        
    int numTilePossibilities(string a) {        
        n = a.size();
        vector<bool> vis(n);
        go("", a, vis);
        return s.size() - 1;
    }
};