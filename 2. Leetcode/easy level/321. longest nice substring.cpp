// link to question - https://leetcode.com/problems/longest-nice-substring/

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        vector<int> a(26), b(26);
        
        int len = 0;
        string ans;
        
        for(int i = 0; i < n; i++) {                        
            for(int j = i; j < n; j++) {
                if(s[j] >= 'a' and s[j] <= 'z') a[s[j] - 'a']++;
                else b[s[j] - 'A']++;
                
                bool f = false;
                for(int k = 0; k < 26; k++) {
                    if((a[k] and !b[k]) or (!a[k] and b[k])) {
                        f = true;
                        break;
                    }
                }

                if(!f and j - i > len) {
                    len = j - i;
                    ans = s.substr(i, j - i + 1);
                }
            }                        
            
            fill(a.begin(), a.end(), 0);
            fill(b.begin(), b.end(), 0);
        }
        
        return ans;
    }
};