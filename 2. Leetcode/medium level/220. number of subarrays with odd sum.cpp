// link to question - https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int n = a.size(), ans = 0;
        int mod = 1e9 + 7;
        int odd = 0, c = 0; 
              
        for(int i = 0; i < n; i++) { 
            if(a[i] & 1) odd = !odd;             
            if(odd) c++;             
        } 
                 
        for(int i = 0; i < n; i++) { 
            ans += c; 
            ans %= mod;
            if(a[i] & 1) c = (n - i - c);             
        } 

        return ans;
    }
};