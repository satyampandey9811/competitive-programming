// link to question - https://leetcode.com/problems/candy/

class Solution {
public:
    // important question
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> b(n, 1);
        for(int i = 1; i < n; i++) {
            if(a[i] > a[i-1]) b[i] = b[i-1] + 1;
        }
        for(int i = n - 2; i >= 0; i--) {
            if(a[i] > a[i+1]) b[i] = max(b[i], b[i+1] + 1);
        }
        return accumulate(b.begin(), b.end(), 0);
    }
};