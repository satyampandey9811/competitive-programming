// link to question - https://leetcode.com/problems/number-of-excellent-pairs/

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        // number of set bits in (num1 OR num2) + number of set bits in (num1 AND num2)
        // = number of set bits in num1 + number of set bits in num2
        
        set<int> s(nums.begin(), nums.end());
        int n = s.size(), ind = 0;
        vector<int> a(n);
        
        for (auto &i :s) {
            a[ind++] = i;
        }
        
        vector<int> suffixSetBits(64), setBits(n);
        int sum, num;
        
        for (int i = 0; i < n; i++) {
            sum = 0, num = a[i];
            while (num > 0) {
                sum++;
                num = num & (num - 1);
            }
            suffixSetBits[sum]++;
            setBits[i] = sum;
        }
        
        for (int i = 30; i >= 0; i--) suffixSetBits[i] += suffixSetBits[i + 1];
        
        long long answer = 0;
        
        for (int i = 0; i < n; i++) {
            if (setBits[i] >= k) answer += n;
            else answer += suffixSetBits[k - setBits[i]];
        }
        
        return answer;
    }
};