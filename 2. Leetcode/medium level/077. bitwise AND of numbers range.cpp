// link to question - https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int c = n - m, ans = n;                
        
        while(c){            
            ans = ans & (n - 1);                  
            if(ans == 0) return 0;
            if(ans <= m) break;
            n = ans;
            c--;
        }
        
        return ans;
    }
};