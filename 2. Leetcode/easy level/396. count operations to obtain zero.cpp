// link to question - https://leetcode.com/problems/count-operations-to-obtain-zero/

class Solution {
public:
    int countOperations(int a, int b) {
        int ans = 0;
        while (a > 0 and b > 0) {
            if (a >= b) a -= b;
            else b -= a;
            ans++;
        }
        return ans;
    }
};