// link to question - https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/

class Solution {
public:
    int numberOfRounds(string s, string f) {
        int st = stoi(s.substr(3, 2)), ft = stoi(f.substr(3, 2));
        if(st >= 1 and st < 15) s[3] = '1', s[4] = '5';
        if(st >= 16 and st < 30) s[3] = '3', s[4] = '0';
        if(st >= 31 and st < 45) s[3] = '4', s[4] = '5';
        if(st >= 46 and st < 60) {
            s[3] = '0', s[4] = '0';
            if(s[1] < '9') s[1]++;
            else {
                s[1] = '0';
                if(s[0] < '2') s[0]++;
                else s[0] = '0';
            }
        }
        
        if(ft >= 1 and ft < 15) f[3] = '0', f[4] = '0';
        if(ft >= 16 and ft < 30) f[3] = '1', f[4] = '5';
        if(ft >= 31 and ft < 45) f[3] = '3', f[4] = '0';
        if(ft >= 46 and ft < 60) f[3] = '4', f[4] = '5';

        int ans = 0;
        
        if(s <= f) {
            int fh = stoi(f.substr(0, 2)), sh = stoi(s.substr(0, 2));
            int fm = stoi(f.substr(3, 2)), sm = stoi(s.substr(3, 2));
            ans = (fh - sh) * 4 - (sm / 15) + (fm / 15);
        }
        else {
            int fh = stoi(f.substr(0, 2)), sh = stoi(s.substr(0, 2));
            int fm = stoi(f.substr(3, 2)), sm = stoi(s.substr(3, 2));
            ans = (sh - fh) * 4 - (fm / 15) + (sm / 15);
            ans = 24 * 4 - ans;
        }
        
        return ans;
    }
};