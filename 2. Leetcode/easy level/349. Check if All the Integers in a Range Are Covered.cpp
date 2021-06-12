// link to question - https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/

class Solution {
public:
    bool isCovered(vector<vector<int>>& a, int l, int r) {
        int n = a.size();
        
        for(int i = l; i <= r; i++) {
            bool g = false;
            
            for(int j = 0; j < n; j++) {
                if(i >= a[j][0] and i <= a[j][1]) {
                    g = true;
                    break;
                }
            }
            
            if(!g) return 0;
        }
        
        return 1;
    }
};