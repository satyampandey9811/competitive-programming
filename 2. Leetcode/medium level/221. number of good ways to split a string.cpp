// link to question - https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

class Solution {
public:
    int numSplits(string a) {                
        int n = a.size(), ans = 0;
        if(n == 1) return 0;
        map<char, int> m, p;
        for(int i = 0; i < n - 1; i++) {
            m[a[i]]++;
        }
        p[a[n-1]]++;
        for(int i = n - 2; i >= 0; i--) {
            if(m.size() == p.size()) ans++;            
            m[a[i]]--;
            if(m[a[i]] == 0) m.erase(a[i]);
            p[a[i]]++;            
        }
        return ans;
    }
};