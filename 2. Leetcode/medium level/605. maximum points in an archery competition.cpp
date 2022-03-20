// link to question - https://leetcode.com/problems/maximum-points-in-an-archery-competition/

class Solution {
public:
    vector<int> b, ans;
    int mx = 0;
    
    void go (int i, int n, vector<int>& a) {
        if (i == 12) {
            int val = 0;
            for (int j = 0; j < 12; j++) {
                if (b[j] > a[j]) val += j;
            }
            if (val > mx) {
                mx = val;
                for (int j = 0; j < 12; j++) ans[j] = b[j];
            }
            return;
        }
        go (i + 1, n, a);
        if (n > a[i]) {
            b[i] = a[i] + 1;
            go (i + 1, n - b[i], a);
        }
        b[i] = 0;
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& a) {
        b = vector<int>(12);
        ans = vector<int>(12);
        go (0, n, a);
        int x = accumulate(ans.begin(), ans.end(), 0);
        ans[0] += n - x;
        return ans;
    }
};