// link to question - https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int maxh = INT_MIN, maxv = INT_MIN;
        for(int i = 1; i < a.size(); i++) {
            maxh = max(maxh, a[i] - a[i - 1]);
        }
        maxh = max({maxh, a[0] - 0, h - a[a.size() - 1]});
        for(int i = 1; i < b.size(); i++) {
            maxv = max(maxv, b[i] - b[i - 1]);
        }
        maxv = max({maxv, b[0] - 0, w - b[b.size() - 1]});
        return (1LL * (maxh % 1000000007) * (maxv % 1000000007)) % 1000000007;
    }
};