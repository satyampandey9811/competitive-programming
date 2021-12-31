// link to question - https://leetcode.com/problems/nth-magical-number/

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low = 1, mid, high = max(a, b) * 1LL * n;
        long long ans, num = n, res;
        int lcm = a * b / __gcd(a, b), mod = 1e9 + 7;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            res = (mid / a) + (mid / b) - (mid / lcm);
            
            if (res >= num) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans % mod;
    }
};