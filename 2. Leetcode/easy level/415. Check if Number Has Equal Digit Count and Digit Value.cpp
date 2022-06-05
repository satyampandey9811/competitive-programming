// link to question - https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/

class Solution {
public:
    bool digitCount(string a) {
        vector<int> c(10);
        int len = a.size();
        
        for (int i = 0; i < len; i++) {
            c[a[i] - '0']++;
        }
        
        for (int i = 0; i < len; i++) {
            if (c[i] != a[i] - '0') {
                return false;
            }
        }
        
        return true;
    }
};