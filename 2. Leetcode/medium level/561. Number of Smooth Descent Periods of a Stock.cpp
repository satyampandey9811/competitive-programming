// link to question - https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        long long answer = 0;
        int i = 0, j = 0;
        int n = a.size();
        
        while (i < n) {
            if (i > 0 and a[i] == a[i-1] - 1) {
                answer += (i - j + 1);
            }
            else {
                j = i;
            }
            if (i == j) answer++;
            i++;
        }
        
        return answer;
    }
};