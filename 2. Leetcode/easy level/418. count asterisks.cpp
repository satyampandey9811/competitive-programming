// link to question - https://leetcode.com/problems/count-asterisks/

class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0, c = 0;
        for (auto &i :s) {
            if (i == '|') c++;
            if (i == '*' and c % 2 == 0) ans++;
        }
        return ans;
    }
};