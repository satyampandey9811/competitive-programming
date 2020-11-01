// link to question - https://leetcode.com/problems/check-array-formation-through-concatenation/

class Solution {
public:
    bool check(vector<int>& a, vector<int>& p, int j) {
        for(int i = 0; i < p.size(); i++, j++) {
            if(a[j] != p[i]) return 0;
        }
        return 1;
    }
    
    bool canFormArray(vector<int>& a, vector<vector<int>>& p) {
        int n = p.size();
        for(int i = 0; i < n; i++) {            
            bool f = false;
            for(int j = 0; j <= a.size() - p[i].size(); j++) {
                if(check(a, p[i], j)) {
                    f = true;
                }
            }
            if(!f) return 0;
        }
        return 1;
    }
};