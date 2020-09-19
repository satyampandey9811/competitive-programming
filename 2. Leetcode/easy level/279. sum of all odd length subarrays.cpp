// link to question - https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& a) {
        int n = a.size();
        long long int sum = 0;
        
        for(int i = 1; i <= n; i += 2) {
            for(int j = 0; j <= n - i; j++) {
                for(int k = j; k < n and k < j + i; k++) {
                    sum += a[k];
                }
            }
        }
        return sum;
    }
};