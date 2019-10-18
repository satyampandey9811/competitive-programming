// link to question - https://leetcode.com/problems/valid-boomerang/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& a) {
        
        if((a[1][1]-a[0][1])*(a[2][0]-a[1][0])==(a[2][1]-a[1][1])*(a[1][0]-a[0][0]))
            return false;
        else
            return true;
    }
};