// link to question - https://leetcode.com/problems/powerful-integers/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {        
        set<int> s;
        int maxi = 0, maxj = 0;
        long long int v = 1;
        
        for(int i = 0; i < 32; i++) {
            v *= x;
            if(v > 1e6) break;
            maxi++;
        }
        v = 1;
        for(int i = 0; i < 32; i++) {
            v *= y;
            if(v > 1e6) break;
            maxj++;
        }
        
        for(int i = 0; i <= maxi; i++) {
            for(int j = 0; j <= maxj; j++) {
                long long int val = pow(x, i) + pow(y, j);
                if(val <= bound) s.insert(val);
            }
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};