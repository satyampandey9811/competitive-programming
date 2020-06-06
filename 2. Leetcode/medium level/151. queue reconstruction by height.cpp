// link to question - https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
        int n = a.size(), x, y, c;
        vector<vector<int>> ans(n, vector<int>(2, -1));
        sort(a.begin(), a.end());                
        
        for(int i = 0; i < n; i++) {
            x = a[i][0], y = a[i][1];
            c = 0;
            for(int j = 0; j < n; j++) {
                if(ans[j][0] == -1 and c == y) {
                    ans[j][0] = x, ans[j][1] = y;
                    break;
                }
                if(ans[j][0] == -1 or ans[j][0] >= x) c++;                
            }
        }
        
        return ans;
    }
};