// link to question - https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

class Solution {
public:
    int minStartValue(vector<int>& a) {
        int ans = 1, sum = 0;
        for(int i = 0; i < a.size(); i++){
            sum += a[i];
            if(sum < 0)
                ans = max(ans, abs(sum) + 1);
        }
        return ans;
    }
};