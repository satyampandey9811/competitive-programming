// link to question - https://leetcode.com/problems/maximum-number-of-pairs-in-array/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& a) {
        int n = a.size();
        vector<int> count(101);
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            count[a[i]]++;
        }
        
        int ans = 0, l = 0;
        
        for (int i = 0; i < 101; i++) {
            ans += count[i] / 2;
            if (count[i] & 1) {
                l++;
            }
        }
        
        res.push_back(ans);
        res.push_back(l);
        
        return res;
    }
};