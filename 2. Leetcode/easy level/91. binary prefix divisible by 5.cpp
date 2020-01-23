// link to question - https://leetcode.com/problems/binary-prefix-divisible-by-5/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& a) {    
        int n = a.size(), sum = a[0];
        vector<bool> ans(n);
        
        ans[0] = (!a[0]) ?true :false;            
        
        for(int i = 1; i < n; i++){
            if(a[i]) sum = sum*2 + 1;
            else sum = sum * 2;
            
            ans[i] = (sum % 5 == 0) ?true :false;
            
            sum = sum % 10;
        }        
        return ans;
    }
};