// link to question - https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();        
        vector<int> ans(n);
        
        for(int l = 0; l < n; l++) {
            int i = 0, j = l, val = -1;
            while(1) {
                if(i == m) {
                    val = j;
                    break;
                }
                if(a[i][j] == 1) {
                    if(j + 1 == n) break;
                    if(a[i][j+1] == -1) break;
                    i++, j++;
                }
                else {
                    if(j - 1 == -1) break;
                    if(a[i][j-1] == 1) break;
                    i++, j--;
                }
            }
            ans[l] = val;
        }
        
        return ans;
    }
};