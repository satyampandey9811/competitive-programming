// link to question - https://leetcode.com/problems/describe-the-painting/

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& a) {
        vector<vector<long long>> ans;
        int n = a.size();
        int mx = 0, s = 1e9;
        
        for(int i = 0; i < n; i++) {
            mx = max(mx, a[i][1]);
            s = min(s, a[i][0]);
        }
        
        vector<long long> c(mx + 1);
        vector<long long> x(mx + 1);
        
        for(int i = 0; i < n; i++) {
            c[a[i][0]] += a[i][2];
            c[a[i][1]] -= a[i][2];
            x[a[i][0]] ^= a[i][2];
            x[a[i][1]] ^= a[i][2];
        }
        
        for(int i = 1; i < mx + 1; i++) {
            c[i] += c[i-1];
        }
        
        for(int i = 1; i < mx + 1; i++) {
            x[i] ^= x[i-1];
        }
        
        for(int i = s + 1; i < mx + 1; i++) {
            
            if(s == -1 and c[i]) {
                s = i;
                continue;
            }
            
            if(c[i] != c[i-1]) {
                ans.push_back({s, i, c[i-1]});
                if(c[i] == 0) s = -1;
                else s = i;
            }
            
            else if(x[i] != x[i-1]) {
                ans.push_back({s, i, c[i-1]});
                if(c[i] == 0) s = -1;
                else s = i;
            }
        }
        
        return ans;
    }
};