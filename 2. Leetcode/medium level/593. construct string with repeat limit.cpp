// link to question - https://leetcode.com/problems/construct-string-with-repeat-limit/

class Solution {
public:
    string repeatLimitedString(string s, int l) {
        vector<int> cnt(26);
        for (auto &ch :s) {
            cnt[ch - 'a']++;
        }
        
        vector<pair<char, int>> a;
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                a.push_back({(char)(i + 'a'), cnt[i]});
            }
        }
        
        string res;
        int n = a.size(), i = n - 1, t;
        
        while (i >= 0) {
            t = min(l, a[i].second);
            
            for (int j = 0; j < t; j++) {
                res += a[i].first;
            }
            
            a[i].second -= t;
            
            if (a[i].second > 0) {
                if (i > 0) {
                    res += a[i - 1].first;
                    a[i - 1].second--;
                    if (a[i - 1].second == 0) {
                        a[i - 1] = a[i];
                        i--;
                        a.pop_back();
                    }
                }
            }
            else {
                i--;
                a.pop_back();
            }
        }
        
        int len = res.size(), c = 1;
        char ch = res.back();
        
        for (int i = len - 2; i >= 0; i--) {
            if (res[i] != ch) break;
            c++;
        }
        
        for (int i = c - l; i > 0; i--) {
            res.pop_back();
        }
        
        return res;
    }
};