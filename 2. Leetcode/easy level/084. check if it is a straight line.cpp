// link to question - https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        
        if(a.size()==2) 
            return true;
        float m=(float)(a[1][1]-a[0][1])/(a[1][0]-a[0][0]);
        for(int i=2;i<a.size();i++){
            float n=(float)(a[i][1]-a[i-1][1])/(a[i][0]-a[i-1][0]);
            if(m!=n)
                return false;
        }
        return true;
    }
};