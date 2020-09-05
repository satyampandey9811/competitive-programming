// link to question - https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        int low = -1, high;
        
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i-1]) {
                low = i;
                break;
            }
        }
        
        if(low == -1) return 0;
        
        for(int i = n - 1; i > 0; i--) {
            if(a[i] < a[i-1]) {
                high = i;
                break;
            }
        }
        
        int ans = high - low;
        int x = low - 1, y = high;
        
        int c = 0, d = 0;
        for(int i = y; i < n; i++) {
            if(a[i] >= a[x]) break;
            c++;
        }
        
        for(int i = x; i >= 0; i--) {
            if(a[i] <= a[y]) break;
            d++;
        }
        
        ans += min(c, d);
        
        return ans;
    }
};