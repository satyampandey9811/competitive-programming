// link to question - https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        int x = l.size(), y = r.size();
        if(x == 0 and y == 0) return 0;
        sort(r.begin(), r.end());
        if(x == 0) return n - r[0];
        sort(l.begin(), l.end());
        if(y == 0) return l.back();        
        return max(l.back(), n - r[0]);
    }
};