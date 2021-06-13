// link to question - https://leetcode.com/problems/maximum-number-of-removable-characters/

class Solution {
public:
    bool go(string& s, string& p) {
        int n = p.size(), m = s.size();
        int i = 0, j = 0;
        while(i < n and j < m) {
            if(p[i] == s[j]) {
                i++, j++;
            }
            else j++;
        }
        return i == n;
    }
    
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int m = s.size(), n = p.size(), r = rem.size();
        int ans = 0;
        
        int low = 0, mid, high = r;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            string z = s;
            for(int i = 0; i < mid; i++) {
                z[rem[i]] = 'G';
            }
            if(go(z, p)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return ans;
    }
};