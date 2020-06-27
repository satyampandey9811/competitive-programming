// link to question - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size(), ans = 0, l = 0, r = 0;
        bool zero = false, one = false;
        for(int i = 0; i < a.size();) {
            if(a[i] == 0) {
                zero = true;
                int j = i + 1;
                r = 0;
                for(; j < n; j++) {
                    if(a[j] == 0) break;
                    one = true;
                    r++;
                }       
                ans = max(ans, l + r);
                l = r;
                i = j;
            }
            else {
                one = true;
                l++;
                i++;
            }
        }        
        if(one and !zero) return n - 1;
        if(!one and zero) return 0;
        return ans;   
    }
};