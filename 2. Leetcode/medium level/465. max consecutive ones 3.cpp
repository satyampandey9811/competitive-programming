// link to question - https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<int> b;
        b.push_back(-1);
        for(int i = 0; i < n; i++) {
            if(!a[i]) b.push_back(i);
        }
        b.push_back(n);
        
        if(b.size() - 2 <= k) return n;
        
        for(int i = 1, j = k; j < b.size() - 1; i++, j++) {
            ans = max(ans, b[j+1] - 1 - b[i-1]);
        }
        for(int i = 1; i < b.size(); i++) {
            ans = max(ans, b[i] - b[i-1] - 1);
        }
        
        return ans;
    }
};