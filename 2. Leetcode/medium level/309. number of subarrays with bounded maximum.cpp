// link to question - https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int l, int r) {
        int ans = 0;
        int n = a.size();
        int high = 0, c = 0, rempos = 1e5, low = 0;
        bool f = false;
        
        for(int i = 0; i < n; i++) {
            high = max(high, a[i]);
            if(a[i] < l) {
                low++;
                f = true;
                rempos = min(rempos, i);
            }
            else {
                if(a[i] > r) low = 0;
                f = false;
                rempos = 1e5;
            }
            
            if(high >= l and high <= r) {                
                if(!c) c = low;
                c++;
                low = 0;
                ans += c;
                if(a[i] < l) ans--;
                if(f) {
                    ans -= i - rempos;
                }
            }
            else {
                c = 0;
                f = false;
                high = 0;
                rempos = 1e5;
            }
        }
        
        return ans;
    }
};