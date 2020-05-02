// link to question - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& a, int e) {
        int n = a.size();
        vector<bool> ans(n);
        int h = *max_element(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            if(a[i] + e >= h)
                ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};