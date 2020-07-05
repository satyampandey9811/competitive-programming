// link to question - https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        int ans = 1e5, n = a.size();
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {            
            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = a[i] + a[j] + a[k];                
                if(abs(t - ans) > abs(t - sum))
                    ans = sum;
                if(sum < t) j++;
                else k--;
            }
        }
        return ans;
    }
};