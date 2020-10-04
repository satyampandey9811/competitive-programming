// link to question - https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {
public:
    int specialArray(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        
        for(int i = 0; i < 1001; i++) {
            int c = 0;
            for(int j = 0; j < n; j++) {
                if(a[j] >= i) c++;
            }
            if(i == c) return i;
        }
        
        return -1;
    }
};