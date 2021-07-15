// link to question - https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int ans = 0, mx;
        mx = *max_element(a.begin(), a.end());
        vector<int> b(mx + 1);
        int n = mx + 1, res, num;
        
        for(int i = 0; i < a.size(); i++) b[a[i]]++;
        b[0] = 0;
        for(int i = 1; i < n; i++) {
            b[i] += b[i-1];
        }
        
        for(int i = 1; i < n; i++) {
            num = b[i] - b[i-1];
            if(num > 0) {
                res = 0;
                for(int j = i + 1; j < n; j++) {
                    int ct = b[j] - b[j-1];
                    if(ct == 0) continue;
                    if(ct > 0) {
                        res += ct * (b[min(n-1,i+j-1)] - b[j]);
                    }
                    if(ct > 1) {
                        res += ct * (ct - 1) / 2;
                    }
                }
                ans += num * res;
            }
            if(num > 1) {
                ans += (b[min(n-1,2*i-1)]-b[i])*num*(num-1)/2;
            }
            if(num > 2) {
                ans += num * (num - 1) * (num - 2) / 6;
            }
        }
        
        return ans;
    }
};