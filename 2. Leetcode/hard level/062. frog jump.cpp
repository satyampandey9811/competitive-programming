// link to question - https://leetcode.com/problems/frog-jump/

class Solution {
public:
    set<int> s;
    map<pair<int, int>, bool> dp;
    int e;
    
    bool go(int i, int j) {
        if(i == e) return 1;
        
        if(dp.count({i, j})) return dp[{i, j}];
        bool ans = false;
        
        for(int k = j - 1; k <= j + 1; k++) {
            if(!s.count(i + k) or i + k == i) continue;
            ans |= go(i + k, k);
            if(ans) break;
        }
        
        return dp[{i, j}] = ans;
    }
    
    bool canCross(vector<int>& a) {
        for(int& i: a) s.insert(i);
        e = a.back();
        return go(0, 0);
    }
};