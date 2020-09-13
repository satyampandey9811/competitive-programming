// link to question - https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        int ans = 0, m = a.size(), n = a[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j]) {
                    bool f = true;
                    for(int k = 0; k < m; k++) {
                        if(k == i) continue;
                        if(a[k][j]) {
                            f = false;
                            break;
                        }
                    }                    
                    for(int k = 0; k < n; k++) {
                        if(k == j) continue;
                        if(a[i][k]) {
                            f = false;
                            break;
                        }
                    }
                    if(f) ans++;
                }
            }
        }
        return ans;
    }
};