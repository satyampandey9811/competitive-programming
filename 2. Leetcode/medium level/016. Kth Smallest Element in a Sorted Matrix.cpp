// link to question - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        int low = a[0][0], high = a[n-1][n-1], mid;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            int c = 0;
            
            for(int i = 0; i < n; i++) {
                int l = 0, r = n - 1, m, ans = -1;
                while(l <= r) {
                    m = l + (r - l) / 2;
                    if(a[i][m] <= mid) ans = m, l = m + 1;  
                    else r = m - 1;
                }
                c += ans + 1;
            }
            
            if(c < k) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};