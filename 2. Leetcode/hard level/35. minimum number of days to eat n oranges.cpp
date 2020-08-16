// link to question - https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

class Solution {
public:
    map<int, int> m;        
    
    int minDays(int n) {                
        if(n < 2) return n;
        if(m.count(n)) return m[n];
        
        int ans = INT_MAX;  
        
        if(n % 3 == 0 and n % 2 == 0) {
            ans = min(ans, 1 + minDays(n - (2 * (n/3))));
            ans = min(ans, 1 + minDays(n - n / 2));
        }
        else if(n % 3 == 0) {
            ans = min(ans, 1 + minDays(n - (2 * (n/3))));
            ans = min(ans, 1 + minDays(n - 1));
        }
        else if(n % 2 == 0) {
            ans = min(ans, 1 + minDays(n - n / 2));
            ans = min(ans, 1 + minDays(n - 1));
        }
        else ans = min(ans, 1 + minDays(n - 1));
        
        return m[n] = ans;
    }
};