// link to question - https://leetcode.com/problems/largest-merge-of-two-strings/

class Solution {
public:
    string largestMerge(string a, string b) {
        string ans;
        int m = a.size(), n = b.size(), i = 0, j = 0, k, l;
        
        while(i < m and j < n) {
            k = i, l = j;
            
            while(k < m and l < n and a[k] == b[l]) k++, l++;
            
            if(k == m) {
                ans += b[j++];
                continue;
            }
            if(l == n) {
                ans += a[i++];
                continue;
            }
            
            if(a[k] > b[l]) ans += a[i++];
            else ans += b[j++];
        }
        
        while(i < m) ans += a[i++];
        while(j < n) ans += b[j++];
        
        return ans;
    }
};