// link to question - https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class Solution {
public:
    vector<int> find (vector<int>& e, int s) {
        int n = e.size();
        vector<int> d(n, INT_MAX);
        d[s] = 0;
        
        queue<int> q;
        q.push(s);
        
        int adj;
        int f;
        
        while (!q.empty()) {
            f = q.front();
            adj = e[f];
            q.pop();
            
            if (adj != -1) {
                if (d[f] + 1 < d[adj]) {
                    q.push(adj);
                    d[adj] = 1 + d[f];
                }
            }
        }
        
        return d;
    }
    
    int closestMeetingNode(vector<int>& e, int n1, int n2) {
        vector<int> a, b;
        int n = e.size();
        
        a = find(e, n1);
        b = find(e, n2);
        
        int res = -1, d = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int sd = max(a[i], b[i]);
            if (sd < d) {
                d = sd;
                res = i;
            }
        }
        
        return res;
    }
};