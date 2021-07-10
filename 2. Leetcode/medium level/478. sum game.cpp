// link to question - https://leetcode.com/problems/sum-game/

class Solution {
public:
    bool sumGame(string s) {
        int n = s.size();
        int ls = 0, lq = 0, rs = 0, rq = 0;
        for(int i = 0; i < n / 2; i++) {
            if(s[i] == '?') lq++;
            else ls += s[i] - '0';
        }
        for(int i = n / 2; i < n; i++) {
            if(s[i] == '?') rq++;
            else rs += s[i] - '0';
        }
        
        int q = lq + rq;
        if(q & 1) return 1;
        if((lq - rq) * 9 / 2 == rs - ls) return 0;
        return 1;
    }
};