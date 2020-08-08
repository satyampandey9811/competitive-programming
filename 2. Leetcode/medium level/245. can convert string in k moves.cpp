// link to question - https://leetcode.com/problems/can-convert-string-in-k-moves/

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return 0;
        int n = s.size();
        map<int, int> m;
        int val;
        for(int i = 0; i < n; i++) {
            if(s[i] == t[i]) continue;            
            if(s[i] < t[i]) {
                val = t[i] - s[i];                                
            }
            else {
                val = 'z' - s[i] + t[i] - 'a' + 1;
            }
            m[val]++;
        }
        for(auto i: m) {
            if(i.first + (i.second - 1) * 26 > k) return 0;
        }
        return 1;
    }
};