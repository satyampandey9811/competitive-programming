// link to question - https://leetcode.com/problems/rectangle-overlap/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) { 
        if(a[0] >= b[2] or b[0] >= a[2] or b[1] >= a[3] or a[1] >= b[3]) 
            return 0;
        return 1;
    }
};