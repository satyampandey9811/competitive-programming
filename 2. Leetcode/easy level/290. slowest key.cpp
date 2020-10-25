// link to question - https://leetcode.com/problems/slowest-key/

class Solution {
public:
    char slowestKey(vector<int>& r, string a) {
        vector<int> c(26);
        int n = a.size();
        if(n) c[a[0] - 'a'] = r[0];
        
        for(int i = 1; i < n; i++) {
            c[a[i] - 'a'] = max(c[a[i] - 'a'], r[i] - r[i-1]);
        }
        
        char ans;
        int val = 0;
        for(int i = 0; i < 26; i++) {
            if(c[i] >= val) {
                val = c[i];
                ans = (char)(97 + i);
            }
        }
        
        return ans;
    }
};