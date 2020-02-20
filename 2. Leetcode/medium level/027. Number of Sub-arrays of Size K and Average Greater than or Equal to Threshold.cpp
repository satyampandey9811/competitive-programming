// link to question - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int t) {
        int n = a.size(), ans = 0, sum = 0;
        int x = 0;
        sum = accumulate(a.begin(), a.begin() + k - 1, 0);
        for(int i = k - 1; i < n; i++){
            sum += a[i];
            if(sum / k >= t) ans++;
            sum -= a[x];
            x++;
        }
        return ans;
    }
};