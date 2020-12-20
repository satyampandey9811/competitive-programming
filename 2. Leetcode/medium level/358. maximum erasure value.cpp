// link to question - https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> b(n + 1);
        b[1] = a[0];
        for(int i = 2; i <= n; i++) {
            b[i] = a[i-1];
            b[i] += b[i-1];
        }
        
        map<int, int> m;
        int ans = 0;
        for (int i = 0, j = 0; i < n ; i++){
            while(j < n and m[a[j]] < 1) {
                m[a[j]]++, j++;
            }                  
            ans = max(ans, b[j] - b[i]);
            m[a[i]]--;                      
        }
        
        return ans;
    }
};