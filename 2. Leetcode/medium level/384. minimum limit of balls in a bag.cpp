// link to question - https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    int minimumSize(vector<int>& a, int k) {
        int n = a.size(), ans, l = 1, r = *max_element(a.begin(), a.end());
        int mid, c;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            
            c = 0;
            for(int i = 0; i < n; i++) {
                c += (a[i] - 1) / mid;
                if(c > k) break;
            }
            
            if(c <= k) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
};