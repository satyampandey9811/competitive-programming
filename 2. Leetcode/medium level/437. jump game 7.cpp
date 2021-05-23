// link to question - https://leetcode.com/problems/jump-game-vii/

class Solution {
public:
    bool canReach(string s, int mnj, int mxj) {
        int n = s.size(), e = 0;
        
        queue<int> q;
        q.push(0);
        
        while(q.size()) {
            
            for(int i = q.size(); i > 0; i--) {
                int g = q.front();
                q.pop();
                
                if(g == n - 1) return 1;
                
                for(int j = max(e + 1, g + mnj); j <= min(n - 1, g + mxj); j++) {
                    e = j;
                    if(s[j] == '1') continue;
                    
                    if(j == n - 1) return 1;
                    q.push(j);
                }
            }
        }
        
        return 0;
    }
};