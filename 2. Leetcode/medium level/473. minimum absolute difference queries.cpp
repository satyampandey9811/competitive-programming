// link to question - https://leetcode.com/problems/minimum-absolute-difference-queries/

class Solution {
public:
    // important question
    vector<int> minDifference(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        int mx = *max_element(a.begin(), a.end());
        vector<vector<int>> st(mx + 1, vector<int>(n + 1));
        
        for(int i = 0; i < n; i++) {
            st[a[i]][i+1]++;
        }
        
        for(int i = 0; i <= mx; i++) {
            for(int j = 1; j <= n; j++) {
                st[i][j] += st[i][j-1];
            }
        }
        
        int qs = q.size(), l, h, s, x;
        vector<int> ans(qs);
        
        for(int i = 0; i < qs; i++) {
            l = q[i][0], h = q[i][1] + 1;
            s = 101, x = -1;
            
            for(int j = mx; j >= 0; j--) {
                if(st[j][h] - st[j][l]) {
                    if(s == 101) {
                        if(x == -1) x = j;
                        else s = x - j, x = j;
                    }
                    else {
                        s = min(s, x - j);
                        x = j;
                    }
                    if(s == 1) break;
                }
            }
            
            if(s == 101) ans[i] = -1;
            else ans[i] = s;
        }
        
        return ans;
    }
};