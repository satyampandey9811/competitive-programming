// link to question - https://leetcode.com/problems/substring-with-largest-variance/

class Solution {
public:
    int largestVariance(string s) {
        int ans = 0, len = s.size();
        vector<vector<int>> a(26);
        
        for (int i = 0; i < len; i++) {
            a[s[i] - 'a'].push_back(i);
        }
        
        int x, y, k;
        int m, n;
        int c, ch;
        
        for (int i = 0; i < 26; i++) {
            if (a[i].size() < 1) continue;
            for (int j = i + 1; j < 26; j++) {
                if (a[j].size() < 1) continue;
                
                x = y = 0;
                vector<int> b;
                c = 0, ch = 0;
                m = a[i].size(), n = a[j].size();
                
                if (x < m and y < n) {
                    if (a[i][x] < a[j][y]) ch = 0;
                    else ch = 1;
                }
                
                while (x < m and y < n) {
                    if (a[i][x] < a[j][y]) {
                        if (!ch) c++;
                        else {
                            b.push_back(c);
                            c = 1;
                            ch = !ch;
                        }
                        x++;
                    }
                    else {
                        if (ch) c++;
                        else {
                            b.push_back(c);
                            c = 1;
                            ch = !ch;
                        }
                        y++;
                    }
                }
                if (x < m) {
                    if (ch) b.push_back(c);
                    c = 0;
                    while (x < m) c++, x++;
                }
                if (y < n) {
                    if (!ch) b.push_back(c);
                    c = 0;
                    while (y < n) c++, y++;
                }
                
                b.push_back(c);
                
                x = y = 0;
                c = -1;
                n = b.size();
                
                for (int k = 0; k < n; k += 2) {
                    if (c >= 0) {
                        ans = max(ans, b[k] + c);
                        c += b[k];
                    }
                    else c = b[k];
                    ans = max(ans, b[k] - 1);
                    
                    if (k + 1 < n) {
                        ans = max(ans, b[k + 1] - 1);
                        c -= b[k + 1];
                    }
                }
                
                c = -1;
                for (int k = 1; k < n; k += 2) {
                    if (c >= 0) {
                        ans = max(ans, b[k] + c);
                        c += b[k];
                    }
                    else c = b[k];
                    if (k + 1 < n) {
                        c -= b[k + 1];
                    }
                }
            }
        }
        
        return ans;
    }
};