// link to question - https://leetcode.com/problems/minimum-operations-to-convert-number/

class Solution {
public:
    int minimumOperations(vector<int>& a, int st, int goal) {
        int n = a.size(), ans = 0;
        int x, y, z;
        unordered_set<int> s;
        
        s.insert(st);
        queue<int> q;
        q.push(st);
        
        while(q.size()) {
            for(int i = q.size(); i > 0; i--) {
                int f = q.front();
                q.pop();
                
                if(f == goal) return ans;
                
                for(int j = 0; j < n; j++) {
                    x = f + a[j], y = f - a[j], z = f ^ a[j];
                    if(x == goal or y == goal or z == goal) return ans + 1;
                    
                    if(!s.count(x) and x >= 0 and x <= 1000) {
                        s.insert(x);
                        q.push(x);
                    }
                    if(!s.count(y) and y >= 0 and y <= 1000) {
                        s.insert(y);
                        q.push(y);
                    }
                    if(!s.count(z) and z >= 0 and z <= 1000) {
                        s.insert(z);
                        q.push(z);
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};