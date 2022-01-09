// link to question - https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        map<string, int> m;
        int n = a.size();
        int res = 0;
        int x, y, val;
        int pep = 0;
        
        for (auto &i :a) m[i]++;
        
        for (int i = 0; i < n; i++) {
            if (m.count(a[i]) < 1) continue;
            
            if (a[i][0] == a[i][1]) {
                val = m[a[i]];
                if (val & 1) {
                    pep = 1;
                    res += 2 * (val - 1);
                }
                
                else res += 2 * val;
                m.erase(a[i]);
            }
            
            else {
                x = m[a[i]];
                string h = a[i];
                h[0] = a[i][1];
                h[1] = a[i][0];
                
                y = m[h];
                res += 4 * min(x, y);
                
                m.erase(a[i]);
                m.erase(h);
            }
        }
        
        res += 2 * pep;
        
        return res;
    }
};