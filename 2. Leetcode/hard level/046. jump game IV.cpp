// link to question - https://leetcode.com/problems/jump-game-iv/

class Solution {
public:        
    int minJumps(vector<int>& a) {
        int n = a.size(), step = 0;
        
        unordered_map<int, vector<int>> m;        
        for(int i = 0; i < n; i++) {
            m[a[i]].push_back(i);                        
        }
        
        queue<int> q;
        q.push(0);
        
        vector<bool> vis(n, false);
        vis[0] = true;                
        
        while(q.size()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                int val = q.front();
                q.pop();
                
                if(val == n - 1) return step;
                
                vector<int>& neighbours = m[a[val]];
                neighbours.push_back(val - 1);
                neighbours.push_back(val + 1);
                
                for(int j: neighbours) {
                    if(j > -1 and j < n and !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                
                neighbours.clear();
            }
            step++;
        }
        
        return 0;
    }
};