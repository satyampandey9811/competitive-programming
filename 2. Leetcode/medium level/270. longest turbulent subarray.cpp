// link to question - https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n = (int)a.size();
        if(n < 2) return n;
        
        int ans = 1, c = 2, s = 0, i = 0;
        
        while(i < n - 1 and a[i] == a[i+1]) i++;
        if(i < n - 1 and a[i] < a[i+1]) s = 1;
        else s = 0;
        
        while(i < n - 1) {
            if(s and a[i] > a[i+1]) c++, s = !s, i++;
            else if(!s and a[i] < a[i+1]) c++, s = !s, i++;
            else {
                if(a[i] == a[i+1]) {
                    while(i < n - 1 and a[i] == a[i+1]) i++;
                    if(a[i] < a[i+1]) s = 1;
                    else s = 0;
                }
                else i++;
                c = 2;
            }
            ans = max(ans, c);            
        }
        
        return ans;
    }
};