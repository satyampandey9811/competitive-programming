// link to question - https://leetcode.com/problems/find-the-middle-index-in-array/

class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
        int n = a.size();
        int ans = -1, left = 0;
        int sum = accumulate(a.begin(), a.end(), 0);
        for(int i = 0; i < n; i++) {
            sum -= a[i];
            if(left == sum) {
                ans = i;
                break;
            }
            left += a[i];
        }
        return ans;
    }
};