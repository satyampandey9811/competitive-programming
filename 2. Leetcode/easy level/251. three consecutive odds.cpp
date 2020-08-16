// link to question - https://leetcode.com/problems/three-consecutive-odds/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n - 2; i++) {
            if((a[i] & 1) and (a[i+1] & 1) and (a[i+2] & 1)) return 1;
        }
        return 0;
    }
};