// link to question - https://leetcode.com/problems/ugly-number-iii/

class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        long long int a = A, b = B, c = C;
        long long int ab = (a * b) / __gcd(a, b);
        long long int bc = (b * c) / __gcd(b, c);
        long long int ac = (a * c) / __gcd(a, c);
        long long int abc = (a * bc) / __gcd(a, bc);
        long long int low = 1, mid, high = 2e9;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            int count = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(count < n) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};            