// link to question - https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        long long int sum = accumulate(arr.begin(), arr.end(), 0LL);
        return sum % k == 0;        
    }
};