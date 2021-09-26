// link to question - Maximum Difference Between Increasing Elements

class Solution {
public:
    int maximumDifference(vector<int>& a) {
        int ans = INT_MIN;
        int n = a.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] < a[j]) {
                    ans = max(ans, a[j] - a[i]);
                }
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};