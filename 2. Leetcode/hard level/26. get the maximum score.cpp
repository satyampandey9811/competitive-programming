// link to question - https://leetcode.com/problems/get-the-maximum-score/

class Solution {
public:
    int maxSum(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size(), i = 0, j = 0;
        long long int ans = 0, sum1, sum2;
        unordered_map<int, int> mp;        
        for(int i = 0; i < n; i++) mp[b[i]] = i;
        
        vector<int> c = {-1}, d = {-1};
        
        for(int i = 0; i < m; i++) {
            if(mp.count(a[i])) {
                c.push_back(i);
                d.push_back(mp[a[i]]);
            }
        }
        
        c.push_back(m-1), d.push_back(n-1);                    
        
        for(int i = 0; i < c.size() - 1; i++) {
            sum1 = 0, sum2 = 0;
            
            int j = c[i] + 1, k = c[i+1];                        
            for(int l = j; l <= k; l++) sum1 += a[l];
            
            j = d[i] + 1, k = d[i+1];            
            for(int l = j; l <= k; l++) sum2 += b[l];
            
            ans += max(sum1, sum2);            
        }
        
        return ans % 1000000007;
    }
};