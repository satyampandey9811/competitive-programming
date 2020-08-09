// link to question - https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

class Solution {
public:
    int maxNonOverlapping(vector<int>& a, int t) {
        unordered_map<int, int> m;
        m[0] = 1;
        int n = a.size(), sum = 0, ans = 0;
        
        for(int i = 0; i < n; i++) {
            sum += a[i];
            if(m.count(sum-t)) {
                ans++;
                m.clear();
                m[0] = 1;
                sum = 0;
            }
            else m[sum]++;
        }
        
        return ans;
    }
};