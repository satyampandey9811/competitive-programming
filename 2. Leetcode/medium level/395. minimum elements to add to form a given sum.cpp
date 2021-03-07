// link to question - https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

class Solution {
public:
    int minElements(vector<int>& a, int l, int g) {
        int n = a.size(), ans;
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        
        if(sum < g) {
            ans = (g - sum) / l;
            if((g - sum) % l) ans++;
        }
        else {
            ans = (sum - g) / l;
            if((sum - g) % l) ans++;
        }
        
        return ans;
    }
};