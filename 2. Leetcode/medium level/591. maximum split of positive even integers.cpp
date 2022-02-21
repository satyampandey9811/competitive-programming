// link to question - https://leetcode.com/problems/maximum-split-of-positive-even-integers/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long f) {
        vector<long long> ans;
        if (f & 1) return ans;
        long long i = 2, sum = 0;
        while (1) {
            if (f - (sum + i) > i) {
                sum += i;
                ans.push_back(i);
            }
            else {
                ans.push_back(f - sum);
                break;
            }
            i += 2;
        }
        return ans;
    }
};