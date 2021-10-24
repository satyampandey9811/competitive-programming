// link to question - https://leetcode.com/problems/count-nodes-with-the-highest-score/

class Solution {
public:
    int n;
    
    int go(int i, vector<vector<int>>& c, vector<int>& nodes) {
        int val = 0;
        for(auto &j :c[i]) {
            val += go(j, c, nodes);
        }
        return nodes[i] = 1 + val;
    }
    
    int countHighestScoreNodes(vector<int>& a) {
        n = a.size();
        vector<vector<int>> c(n);
        for(int i = 1; i < n; i++) {
            c[a[i]].push_back(i);
        }
        
        vector<int> nodes(n, n);
        
        go(0, c, nodes);
        
        long long mx = 0, ct;
        int ans = 0, t;
        
        for(int i = 0; i < n; i++) {
            ct = 1, t = 0;
            for(auto &j :c[i]) {
                ct *= nodes[j];
                t += nodes[j];
            }
            if(n - t - 1) ct *= (n - t - 1);
            
            if(ct > mx) {
                mx = ct;
                ans = 1;
            }
            else if(ct == mx) {
                ans++;
            }
        }
        
        return ans;
    }
};