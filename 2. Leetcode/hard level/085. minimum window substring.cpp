// link to question - https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ms, mt;
        for(auto &c :t) mt[c]++;
        
        int n = s.size();
        int i = 0, j = 0, wsize = INT_MAX;
        string ans;
        
        bool f = false;
        
        while(j < n) {
            if(mt.count(s[j]) < 1) {
                if(!f) i++;
            }
            else {
                ms[s[j]]++;
                f = true;
            }
            bool g = true;
            
            for(auto &k :mt) {
                if(mt[k.first] > ms[k.first]) {
                    g = false;
                    break;
                }
            }
            
            if(g) {
                if(j - i + 1 < wsize) {
                    wsize = j - i + 1;
                    ans = s.substr(i, wsize);
                }
                ms[s[i]]--;
                ms[s[j]]--;
                i++;
                while(i < n and mt.count(s[i]) < 1) i++;
            }
            else j++;
        }
        
        return ans;
    }
};