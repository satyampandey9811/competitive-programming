// link to question - https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& a, vector<int>& t) {
        int n = a.size();
        bool p = false, q = false, r = false;
        
        for(int i = 0; i < n; i++) {
            if(a[i][0] == t[0] and a[i][1] <= t[1] and a[i][2] <= t[2]) {
                p = true;
                break;
            }
        }
        if(!p) return 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i][1] == t[1] and a[i][0] <= t[0] and a[i][2] <= t[2]) {
                q = true;
                break;
            }
        }
        if(!q) return 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i][2] == t[2] and a[i][0] <= t[0] and a[i][1] <= t[1]) {
                r = true;
                break;
            }
        }
        if(!r) return 0;
        
        return 1;
    }
};