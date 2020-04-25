// link to question - https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        if(n < 2) return 1;
        int start = a[0];
        
        for(int i = 0; i < n - 1; i++){
            start--;
            start = max(start, a[i]);
            if(start < 1) return 0;
        }
        return 1;
    }
};