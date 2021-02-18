// link to question - https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size(), ans = 0, c = 0;
        for(int i = 2; i < n; i++) {
            if(a[i] - a[i-1] == a[i-1] - a[i-2]) c++;
            else c = 0;
            ans += c;
        }
        return ans;
    }
};