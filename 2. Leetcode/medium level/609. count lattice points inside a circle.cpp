// link to question - https://leetcode.com/problems/count-lattice-points-inside-a-circle/

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& a) {
        int ans = 0;
        int n = a.size(), x, y;
        
        set<pair<int, int>> s;
        
        for (int i = 0; i < n; i++) {
            for (int j = a[i][0] - 100; j <= a[i][0] + 100; j++) {
                for (int k = a[i][1] - 100; k <= a[i][1] + 100; k++) {
                    x = abs(j - a[i][0]);
                    x *= x;
                    y = abs(k - a[i][1]);
                    y *= y;
                    
                    if (x + y - a[i][2] * a[i][2] <= 0) {
                        s.insert({j, k});   
                    }
                }
            }
        }
        
        ans = s.size();
        
        return ans;
    }
};