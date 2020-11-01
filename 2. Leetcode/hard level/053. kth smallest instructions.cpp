// link to question - https://leetcode.com/problems/kth-smallest-instructions/

class Solution {
public:    
    string ans;
    int h = 0, v = 0;
    
    string kthSmallestPath(vector<int>& dest, int k) {       
        int x = dest[0], y = dest[1];
        vector<vector<int>> a(x + 1, vector<int>(y + 1, 1));                                
        
        for(int i = 1; i < x + 1; i++) {
            for(int j = 1; j < y + 1; j++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }            
        }
        
        int mx = 0, my = y;                  
        
        while(k > 0) {
            if(a[x-mx][y-my] < k) {                
                my--;
            }
            else {
                if(y - my < 1) mx++;
                else if(y - my > 0 and a[x-mx][y-my-1] < k) {
                    k -= a[x-mx][y-my-1];
                    mx++;
                }
                else {
                    my++;
                }
                
                for(int i = h; i < my; i++) ans += 'H';
                for(int i = v; i < mx; i++) ans += 'V';
                h = my, v = mx;
            }
            if(mx == x and my == y) break;
        }
        
        return ans;
    }
};