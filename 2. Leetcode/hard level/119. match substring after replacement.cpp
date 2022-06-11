// link to question - https://leetcode.com/problems/match-substring-after-replacement/

class Solution {
public:
    bool go (int i, string &s, string &sub, vector<vector<char>>& map) {
        int x;
        int n = sub.size();
        
        for (int j = 0; j < n; j++) {
            if (s[i] == sub[j]) {
                i++;
            }
            else {
                if (sub[j] >= 'A' and sub[j] <= 'Z') x = 26 + (sub[j] - 'A');
                else if (sub[j] >= 'a' and sub[j] <= 'z') x = sub[j] - 'a';
                else x = 52 + (sub[j] - '0');
                
                bool g = true;
                
                for (int k = map[x].size() - 1; k >= 0; k--) {
                    if (s[i] == map[x][k]) {
                        g = false;
                        break;
                    }
                }
                
                if (g) {
                    return false;
                }
                
                i++;
            }
        }
            
        return 1;
    }
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mt) {
        vector<vector<char>> mp(62);
        int m = sub.size();
        int n = s.size();
        
        for (auto &i :mt) {
            char c = i[0];
            
            if (c >= 'A' and c <= 'Z') mp[26 + (c - 'A')].push_back(i[1]);
            else if (c >= 'a' and c <= 'z') mp[c - 'a'].push_back(i[1]);
            else mp[52 + (c - '0')].push_back(i[1]);
        }
        
        for (int i = 0; i <= n - m; i++) {
            if (go(i, s, sub, mp)) {
                return 1;
            }
        }
        
        return 0;
    }
};