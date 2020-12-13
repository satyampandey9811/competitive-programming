// link to question - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution {
public:
    int minPartitions(string a) {
        int ans = 0;
        for(int i = 0; i < a.size(); i++) {
            ans = max(ans, a[i] - '0');
        }
        return ans;
    }
};