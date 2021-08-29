// link to question - https://leetcode.com/problems/find-the-kth-largest-element-in-an-array/

class Solution {
public:
    string kthLargestNumber(vector<string>& a, int k) {
        int n = a.size();
        vector<pair<int, string>> b(n);
        for(int i = 0; i < n; i++) {
            b[i] = {a[i].size(), a[i]};
        }
        sort(b.begin(), b.end());
        return b[n-k].second;
    }
};