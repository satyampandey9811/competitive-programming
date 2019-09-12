// link to question - https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& a) {        
        short int i=max_element(a.begin(),a.end())-a.begin();
        short int max=a[i];
        for(auto x:a){
            if(x!=max and max<2*x)
                return -1;
        }
        return i;
    }
};