// link to question - https://leetcode.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int time) {
        int n = a.size();
        
        vector<int> inc(n), dec(n);
        vector<int> ans;
        
        for (int i = 1; i < n; i++) {
            if (a[i-1] >= a[i]) dec[i] = dec[i-1] + 1;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (a[i+1] >= a[i]) inc[i] = inc[i+1] + 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (inc[i] >= time and dec[i] >= time) ans.push_back(i);
        }
        
        return ans;
    }
};