// link to question - https://leetcode.com/problems/divide-array-into-equal-pairs/

class Solution {
public:
    bool divideArray(vector<int>& a) {
        vector<int> c(501);
        
        for (int i = 0; i < (int)a.size(); i++) c[a[i]]++;
        
        for (int i = 0; i < 501; i++) {
            if (c[i] % 2 > 0) return 0;
        }
        
        return 1;
    }
};