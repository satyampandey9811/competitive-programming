// link to question - https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/

class Solution {
public:
    bool canChoose(vector<vector<int>>& g, vector<int>& a) {
        int m = g.size(), n = a.size();
        int c = 0, i = 0, k = 0, l;
                
        while(i < m) {
            bool f = true;
            l = k;
            for(int j = 0; j < g[i].size(); j++) {
                if(k == n) return 0;
                if(a[k] != g[i][j]) {
                    f = false;
                    break;
                }
                k++;
            }
            if(f) {
                c++;
                i++;
            }
            else {
                k = l + 1;
            }

            if(c == m) return 1;
        }
        
        return 0;
    }
};