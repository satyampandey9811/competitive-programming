// link to question - https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        vector<int> c(n);
        
        for(int i = 0; i < n; i++) {
            int cnt = 0, j = n - 1;
            while(j >= 0 and grid[i][j] == 0) cnt++, j--;
            c[i] = cnt;
        }
        
        for(int i = 0; i < n; i++) {
            int d = n - i - 1;
            if(c[i] >= d) continue;
            
            bool f = 1;            
            for(int j = i + 1; j < n; j++) {
                if(c[j] >= d) {
                    for(int k = j; k > i; k--) ans++, swap(c[k], c[k-1]);
                    f = 0; 
                    break;
                }                
            }
            
            if(f) return -1;                        
        }
        
        return ans;
    }
};