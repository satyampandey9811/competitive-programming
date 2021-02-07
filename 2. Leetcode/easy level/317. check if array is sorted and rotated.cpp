// link to question - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& a) {
        int ind = 0, n = a.size();                                        
        
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i-1]) {
                ind = i;
                break;
            }
        }
        for(int i = ind + 1; i < n; i++) {
            if(a[i] < a[i-1]) return 0;
        }
        if(ind != 0 and a[0] < a.back()) return 0; 
        for(int i = 0; i < ind - 1; i++) {
            if(a[i] > a[i+1]) return 0;
        }
        return 1;
    }
};