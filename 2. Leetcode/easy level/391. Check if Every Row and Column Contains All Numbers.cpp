// link to question - https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

class Solution {
public:
    bool checkValid(vector<vector<int>>& a) {
        int n = a.size(), total = n * (n + 1) / 2;
        
        for (int i = 0; i < n; i++) {
            set<int> now;
            for (int j = 0; j < n; j++) {
                now.insert(a[i][j]);
            }
            
            if (now.size() < n) return false;
        }
        
        for (int i = 0; i < n; i++) {
            set<int> now;
            for (int j = 0; j < n; j++) {
                now.insert(a[j][i]);
            }
            
            if (now.size() < n) return false;
        }
        
        return true;
    }
};