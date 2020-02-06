// link to question - https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size(), x;        
        for(int i = 0; i < n; i++){              
            x = a[i] % (n + 1);
            if(x == n) continue;
            a[x] += n + 1;
        }        
        for(int i = 0; i < n; i++){
            if(a[i] / (n + 1) == 0)
                return i;
        }    
        return n;
    }
};