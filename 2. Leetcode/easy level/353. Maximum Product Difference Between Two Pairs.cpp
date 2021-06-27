// link to question - Maximum Product Difference Between Two Pairs

class Solution {
public:
    int maxProductDifference(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = a.back() * a[n-2] - (a[0] * a[1]);
        return ans;
    }
};