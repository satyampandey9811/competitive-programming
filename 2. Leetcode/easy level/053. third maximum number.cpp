// link to question - https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& a) {
        
        set<int> b(a.begin(),a.end());
        auto it=b.end();
        
        if(b.size()<3){
            advance(it,-1);
            return *it;
        }
        advance(it,-3);
        return *it;
    }
};