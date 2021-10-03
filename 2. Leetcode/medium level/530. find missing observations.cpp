// link to question - https://leetcode.com/problems/find-missing-observations/

class Solution {
public:
    vector<int> missingRolls(vector<int>& a, int mean, int n) {
        int m = a.size();
        vector<int> ans(n, 1);
        
        int sum = accumulate(a.begin(), a.end(), 0);
        sum = mean * (m + n) - sum;
        sum -= n;
        
        if(sum < 0) return {};
        
        for(int i = 0; i < n; i++) {
            if(sum > 5) {
                ans[i] += 5;
                sum -= 5;
            }
            else {
                ans[i] += sum;
                sum = 0;
                break;
            }
        }
        if(sum) return {};
        
        return ans;
    }
};